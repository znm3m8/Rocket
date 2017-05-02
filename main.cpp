#include <iostream>
#include "atm.h"
using namespace std; 

const double pi = 3.14159265;

const double i2m = .0254;

class Rocket{
	public:
		double height(Rocket r1){
			return 4000;
		}
	private:
		double diameter;

};

int main(){
	atm test;
	double test2 = test.pres(1000);
	cout << test2 << endl;
	return 0;
}

