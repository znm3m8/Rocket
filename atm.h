#ifndef ATM_H
#define ATM_H

class atm{
	private:
		double T;
		double P;
		double rho;
		double h;
		double offT;
		double scP;
	public:
		atm(double H, double offT, double scP);
		double temp(double H, double offT);
		double pres(double H, double scP);
		double dens(double H, double offT, double scP);
};

#endif
