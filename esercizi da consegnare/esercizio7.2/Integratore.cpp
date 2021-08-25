#include <algorithm>
#include <cmath>

#include "Integratore.h"

using namespace std;

Integral::Integral(double a, double b, FunzioneBase *f)
{
	_integrand = f;
	_integral = 0;
	_a = min(a,b);
	_b = max(a,b);

	if (a > b)
		_sign = -1;
	else
		_sign = 1;
}

double Integral::midpoint (int nstep)
{
	_sum = 0.;
	_h = (_b - _a)/nstep;

	for (int i = 0; i < nstep; ++i)
	{
		double x = _a + (i + 0.5)*_h;
		_sum += _integrand->Eval(x);
	}

	_integral = _sign * _sum * _h;
	return _integral;
}

double Integral::simpson (int nstep)
{
	_h = (_b - _a)/nstep;
	_sum = (_integrand->Eval(_a + 0.5 * _h) + _integrand->Eval(_b - 0.5 * _h)/3);

	for (int i = 1; i < nstep-1; ++i)
	{
		double x = _a + (i + 0.5) *_h;

		switch (i % 2)
		{
			case 0:
			{
				x = x * 2;
				break;
			}
			case '1':
			{
				x = x * 4;
				break;
			}
		}
		_sum += _integrand->Eval(x)/3;
	}

	_integral = _sign * _sum * _h;
	return _integral;
}

double Integral::trapezoide (double eps)
{
	unsigned int n = (_b - _a) / eps;
	unsigned int i = 0;
	_sum = 0;

	for (i; i < n; i++)
		_sum += _integrand->Eval(_a + i*eps);
	
	double m = ( _integrand->Eval(_a) + _integrand->Eval(_b) )/2;

	_integral = _sign * eps * (_sum + m);
	
	return _integral;
}

/*{
	_h = _sign * (_b - _a);
	unsigned int n = 0; unsigned int i;
	double xm;

	_sum = ( _integrand->Eval(_a)+_integrand->Eval(_b) )/2;
	_integral = _sum * _sign * (_b - _a) / pow(2,n);

	while(_h > eps)
	{
		n += 1;
		
		for(i = 0; i <= pow(2,n); i++)
		{
			xm = (_a + _b)/pow(2,n) + i*(_b - _a) / pow(2,n-1);
			_sum += _sum + _integrand->Eval(xm);
		}

		_integral += _sum * _sign *(_b - _a) / pow(2,n);

		_h /= pow(2,n);
	}

	return _integral;
}*/
