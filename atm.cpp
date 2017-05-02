#include <iostream>
#include "atm.h"

using namespace std;

double atm::temp(double H)
{
	double T;
	int US_H [7] = {0, 11000, 20000, 32000, 47000, 51000, 71000}
	double US_T [7] = {288.15, 216.65, 216.65, 228.65, 270.65, 270.65, 214.65};
	double US_R [7] = {-.0065, 0, .001, .0028, 0, -.0028, -.002};
	
	if(H < US_H(1))
		T = US_T(0) + US_R(0)*(H-US_H(0));
	elseif(H < US_H(2))
		T = US_T(1) + US_R(1)*(H-US_H(1));
	elseif(H < US_H(3))
		T = US_T(2) + US_R(2)*(H-US_H(2));
	elseif(H < US_H(4))
		T = US_T(3) + US_R(3)*(H-US_H(3));	
	elseif(H < US_H(5))
		T = US_T(4) + US_R(4)*(H-US_H(4));
	elseif(H < US_H(6))
		T = US_T(5) + US_R(5)*(H-US_H(5));
	else
		T = US_T(6) + US_R(6)*(H-US_H(6));	
	return T;
}

double atm::pres(double H)
{
	double P = 101325;
	return P;
}

double atm::dens(double H)
{
	double rho = 1.225;
	return rho;
}
