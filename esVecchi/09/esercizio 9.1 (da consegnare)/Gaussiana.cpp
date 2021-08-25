#include <cmath>

#include "FunzioneBase.h"
#include "Gaussiana.h"

using namespace std;


Gaussiana::Gaussiana()
{
	_mi = 0;
	_sigma = 0;
}

Gaussiana::Gaussiana(double mi, double sigma)
{
	_mi = mi;
	_sigma = sigma;
}

double Gaussiana::Eval(double x) const
{
	return (1/_sigma * sqrt(2 * M_PI) * exp(-pow(x-_mi,2)/(pow(_sigma,2))));
}
