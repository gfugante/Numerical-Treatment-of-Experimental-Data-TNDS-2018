#include <algorithm>
#include <iostream>

#include "Integratore.h"
#include "FunzioneBase.h"

using namespace std;

Integral::Integral(double a, double b, FunzioneBase *f)
{
	_integrand = f;
	_a = min(a,b);
	_b = max(a,b);

	if (a > b)
		_sign = -1;
	else
		_sign = 1;
}


double Integral::Trapezoide (double eps)
{
	unsigned int n = (_b - _a) / eps;
	unsigned int i = 0;
	_sum = 0.;

	for (i; i < n; i++)
		_sum += _integrand->Eval(_a + i * eps);
	
	double m = ( _integrand->Eval(_a) + _integrand->Eval(_b) )/2;

	_integral = _sign * eps * (_sum + m);
	
	return _integral;
}


