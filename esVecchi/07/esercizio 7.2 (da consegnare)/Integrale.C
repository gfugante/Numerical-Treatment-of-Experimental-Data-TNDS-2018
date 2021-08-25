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

Integral::Integral(double a, double b, double prec, FunzioneBase* function){
	_integrand = function;
	_a=min(a,b);
	_b=max(a,b);
	if (a>b) _sign=-1;
	else _sign=1;

	_prec = prec;
	
	
}

double Integral::trapezi(){
	double integral1,delta,c;
	int nstep = 2;
	
	_sum = (_integrand->Eval(_a)+_integrand->Eval(_b))/2;
	integral1 = _sum*(_b-_a)*_sign;

	_sum = _sum + _integrand->Eval((_b-_a)/2);
	_integral = _sum*((_b-_a)/2)*_sign;	
	c = _integral-integral1;
	
	while(c>_prec || c<-_prec){
		delta = (_b-_a)/nstep;
		_h = delta/2;
		for(unsigned int i=0; i<nstep-1; i++) _sum += _integrand->Eval(_h+(i*delta));
		integral1 = _integral;
		_integral = (_sum/2*nstep)*_sign;
		nstep = nstep*2;
		c = _integral-integral1;
	}
	return _integral;
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
