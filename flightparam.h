#ifndef FLIGHTPARAM_H
#define FLIGHTPARAM_H
#include "atm.h"

class flightparam{
	private:
		double i;
		double t;
		double dt;
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
		node *next;

	public:
		flightparam(flightparam Prev);
		

		double acc(flightparam Prev);
		double vel(flightparam Prev);
		double height(flightparam Prev);
		double netF(flightparam Prev);
		double drag(flightparam Prev);
		double weight(flightparam Prev);
		double thrust(flightparam Prev);
		double cd(flightparam Prev);
		double cf(flightparam Prev);
		double mach(flightparam Prev);
};

#endif
