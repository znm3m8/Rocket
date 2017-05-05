#include <iostream>
#include "atm.h"
#include "engine.h"
#include "flightparam.h"

using namespace std; 

const double pi = 3.14159265;


int main(){
	double offT = 0;
	double scP = 1;
	
	for(double initH = 0; initH <100000; initH+=5000)
	{
		atm A(initH, offT, scP);
		cout << "\n\n";
	}

	return 0;
}

