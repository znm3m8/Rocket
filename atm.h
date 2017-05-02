#ifndef ATM_H
#define ATM_H

class atm{
	private:
		double T;
		double P;
		double rho;
		double h;
	public:
		double temp(double H);
		double pres(double H);
		double dens(double H);
};

#endif
