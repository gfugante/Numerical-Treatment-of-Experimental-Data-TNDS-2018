#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

#include "Seno.h"
#include "Integratore.h"

using namespace std;

int main (int argc, const char** argv)
{
	if (argc != 2)
	{
		cout << "stai usando: <esercizio7.2> <precisione>" << endl;
		return -1;
	}

	double a = 0.;
	double b = M_PI;

	double epsilon = atof(argv[1]);

	FunzioneBase *seno = new Seno();
	Integral *integrale = new Integral(a, b, seno);

	cout << setprecision(7) << integrale->trapezoide(epsilon) << endl;	
	
	return 0;
}
