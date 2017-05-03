#include <iostream>
#include <tgmath.h>
#include <math.h>
#include "atm.h"

using namespace std;

double atm::temp(double H, double offT)
{
	double T;
	double sR;
	double sH;
	double sT;
	
	int US_H [8] = {0, 11000, 20000, 32000, 47000, 51000, 71000, 86000};
	double US_T [7] = {288.15, 216.65, 216.65, 228.65, 270.65, 270.65, 214.65};
	double US_R [7] = {-.0065, 0, .001, .0028, 0, -.0028, -.002};
	bool inAtm = false;

	for(int i = 7; i > 0; i--)
	{
		if( H < US_H [ i ])
		{
			sR = US_R [ i-1 ];
			sH = US_H [ i-1 ];
			sT = US_T [ i-1 ];
			inAtm = true;
		}
	}

	if(inAtm)
	{
		T = sT + sR*(H - sH);
	}
	else
	{
		T = US_T [ 6 ] + US_R [ 6 ] * ( US_H [7] - US_H [6]);
	}

	T = T + offT;

	return T;
}

double atm::pres(double H, double scP)
{
	double P;
	double sP;
	double sR;
	double sT;
	double sH;
	
	double g = 9.80665;
	double M = .0289644;
	double R = 8.3144598;
		
	int US_H [8] = {0, 11000, 20000, 32000, 47000, 51000, 71000, 86000};
	double US_T [7] = {288.15, 216.65, 216.65, 228.65, 270.65, 270.65, 214.65};
	double US_R [7] = {-.0065, 0, .001, .0028, 0, -.0028, -.002};
	double US_P [7] = {101325, 22632.1, 5474.89, 868.019, 110.906, 66.9389};
	bool inAtm = false;

	for(int i = 7; i > 0; i--)
	{
		if( H < US_H [ i ])
		{
			sP = US_P [ i-1 ];
			sR = US_R [ i-1 ];
			sT = US_T [ i-1 ];
			sH = US_H [ i-1 ];
			inAtm = true;
		}
	}


	if(inAtm)
	{
		if(sR == 0)
			P = sP*exp(-g*M*(H-sH)/(R*sT));
		else
			P = sP*pow( sT/(sT+sR*(H-sH)), g*M/(R*sR));

	}
	else
	{
		P = 0;
	}


	P = P*scP;
	return P;
}

double atm::dens(double H, double offT, double scP)
{
	double P = pres(H, scP);
	double T = temp(H, offT);
	double R = 8.3144598/.0289644;
	double rho = P/(R*T);
	
	return rho;
}

atm::atm(double H, double offT, double scP)
{
	this->offT = offT;
	this->scP = scP;
	this->P = pres(H, scP);
	this->T = temp(H, offT);
	this->rho = dens(H, offT, scP);
	this->h = H;

	cout << this->h << "\t";
	cout << this->P << "\t";
	cout << this->T;

}

