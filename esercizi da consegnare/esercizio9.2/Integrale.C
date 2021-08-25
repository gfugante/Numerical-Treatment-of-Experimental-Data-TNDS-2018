#include "Integrale.h"
#include "Random.h"
#include <algorithm>
#include <cmath>
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

double Integral::hitormiss(int nstep, double max){
	static int h = 1;
	Random r (h);
	h++;
	
	int n = 0;
	int N = 0;
	double x,y,s,t;
	
	while(n<nstep){
		s = r.Rand();
		t = r.Rand();
	
		x = _a + (_b-_a)*s;
		y = max*t;
		if(y<=_integrand->Eval(x)) n++;
		N++;
	}
	x = ((_b-_a)*max)*((n*1.)/(N*1.));
	
	return x;
}

double Integral::media(int nstep){
	_sum = 0.;
	static int j = 1;
	Random r (j);
	j++;
	
	for(unsigned int i=0; i<nstep; i++){
		_sum += _integrand->Eval(r.Uniform(_a,_b));
	}
	return (_sum/nstep)*(_b-_a);
}
