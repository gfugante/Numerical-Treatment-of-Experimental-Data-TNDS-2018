#include "Integrale.h"
#include <algorithm>

using namespace std;

Integral::Integral(double a, double b, FunzioneBase* function){
	_integrand = function;
	_a=min(a,b);
	_b=max(a,b);
	if (a>b) _sign=-1;
	else _sign=1;
	
}
double Integral::midpoint(int nstep){

	_sum = 0.;
	_h = (_b-_a)/nstep;
	for(int i=0; i<nstep; ++i){
		double x =  _a+(i+0.5)*_h;	
		_sum += _integrand->Eval(x);
	}
	_integral = _sign*_sum*_h;
	return _integral;

}


double Integral::simpson(int nstep){

	_sum = _integrand->Eval(_a+(0.5*_h)) + _integrand->Eval(_b-(0.5*_h));
	_h = (_b-_a)/nstep;

	for (int i=1; i<nstep-1; ++i){
		double x = _a + (i+0.5)*_h;
		if(i%2==0)	_sum += 4*_integrand->Eval(x);	
		else _sum += 2*_integrand->Eval(x);	
	}
	_integral = (_sign*_sum*_h)/3;
	return _integral;
	
}
