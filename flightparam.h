#ifndef FLIGHTPARAM_H
#define FLIGHTPARAM_H


class flightparam{
	private:
		double i;
		double t;
		double H;
		double v;
		double a;
		double netF;
		double Drag;
		double Thrust;
		double Weight;
		double Mass;
		double mprop;
		double Mach;
		double Cf;
		eng Engine;
		atm Atmos;

	public:
		flightparam(flightparam Prev);
		

		double acc(double netF, double Mass);
		double vel(double prevA, double prevV);
		double height(double prevV, double prevH);
		double netF(double Drag, double Weight, double Thrust, double Mass);
		double drag(double Cd, double v, atm Atmos);
		double weight(double mass, double height);
		double thrust(double Cf, double cstar, double mdot)A;
		double cd(double Mach);
		double cf(double k, double Pc, double Pa, double esp);
		double mach(double v, double T);
};

#endif
