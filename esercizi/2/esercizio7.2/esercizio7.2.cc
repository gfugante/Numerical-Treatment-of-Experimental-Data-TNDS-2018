#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "funzioneBase.h"
#include "seno.h"
#include "integrale.h"

using namespace std;

int main(){
	
	double a=0.;
	double b= M_PI;

	funzioneBase * sin = new seno();
	integrale * integral = new integrale(a, b, sin, 1E-6);
	cout<<integral->trapezoidi(1000)<<endl;
	cout<<integral->trapezoidiFissata()<<endl;

	return 0;
}
	
