#include <cmath>
#include <iostream>
#include "FunzioneBase.h"
#include "FunzioneIntegrale.h"

using namespace std;


ATheta::ATheta()
{
	_r = 0.;
	_lambda = 0.;
	_theta = 0.;
}

double ATheta::Eval(double t) const
{
	double r2 = _r*_r;
	double t2 = t*t;
	
	return (2*sqrt(r2-t2)/(M_PI*r2))*cos(t*sin(_theta)/_lambda);
}






