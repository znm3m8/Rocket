#include <iostream>
#include "flightparam.h"
#include "engine.h"
#include "atm.h"

using namespace std;

double flightparam::acc(flightParam prev)
{
	double netF = netF(prev);
	double mass = mass(prev);

	double a = netF/mass;
	return a;
}

double flightparam::vel(flightParam prev)
{
	double v = prevV + a*dt;
	return v;
}

double flightparam::height(flightParam prev)
{
	double h = prevH + v*dt;
	return h;
}

double flightparam::netF(flightParam prev)
{
	double Drag = drag(prev);
	double Weight = weight(prev);
	double Thrust = thrust(prev);

	double netF = Drag + Weight + Thrust;
	return netF;
}

double flightparam::drag(flightParam prev)
{
	double rho = prev.getrho();
	double v = prev.getV();
	double Cd = cd(prev);
	double S = 5;

	double drag = .5*rho*v^2*Cd*S;
	return drag;
}
