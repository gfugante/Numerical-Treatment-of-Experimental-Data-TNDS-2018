#include <algorithm>
#include <iostream>

#include "Integratore.h"
#include "Random.h"
#include "Vettore.h"

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

double Integral::midpoint (unsigned int nstep)
{
	_sum = 0.;
	_h = (_b - _a)/nstep;

	for (unsigned int i = 0; i < nstep; ++i)
	{
		double x = _a + (i + 0.5) * _h;
		_sum += _integrand->Eval(x);
	}

	_integral = _sign * _sum * _h;
	return _integral;
}

double Integral::simpson (unsigned int nstep)
{
	_h = (_b - _a) / nstep;
	_sum = _integrand->Eval( _a + (0.5 * _h) ) + _integrand->Eval( _b - (0.5 * _h) );

	for (unsigned int i = 1; i < nstep-1; ++i)
	{
		double x = _a + (i + 0.5) * _h;
		
		if(i % 2 == 0)	
			_sum += 4*_integrand->Eval(x);	
		
		else 
			_sum += 2*_integrand->Eval(x);	
	}
	_integral = (_sign * _sum * _h) / 3;
	return _integral;
}

double Integral::trapezoide (double eps)
{
	unsigned int n = (_b - _a) / eps;
	unsigned int i = 0;
	_sum = 0;

	for (i; i < n; i++)
		_sum += _integrand->Eval(_a + i * eps);
	
	double m = ( _integrand->Eval(_a) + _integrand->Eval(_b) )/2;

	_integral = _sign * eps * (_sum + m);
	
	return _integral;
}

double Integral::hitormiss(unsigned int nstep, double max){
	Random r (9);
	int n = 0;
	int N = 0;
	double x,y,s,t;
	
	while(n < nstep){
		s = r.Rand();
		t = r.Rand();
	
		x = _a + (_b - _a) * s;
		y = max * t;
		if( y <= _integrand->Eval(x) ) 
			n++;
		N++;
	}
	x = ( (_b - _a) * max) * ( (n * 1.) / (N * 1.) );
	
	return x;
}

double Integral::media(unsigned int nstep, unsigned int dim){
	_sum = 0.;
	_integral = 0.;
	static double Imid = 0;
	static Random r (15);
	Vettore coord(dim);
	
	for(unsigned int i = 0; i < nstep; i++)
	{
		for (unsigned int j = 0; j < dim; j++)
			coord.SetComponent( j, r.Uniform(_a,_b) );

		_sum += _integrand->Eval( coord.modulo() );
	}
	Imid = _sum / nstep;
	for (unsigned int k = 0; k < dim; k++)
		Imid *= (_b - _a);

	return Imid;
}
