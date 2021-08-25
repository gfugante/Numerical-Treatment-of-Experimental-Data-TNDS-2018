#include "integrator.h"
#include <algorithm>

using namespace std;

integral::integral(double a, double b, funzioneBase* function){
	_integrand = function;
	_a= min(a,b);
	_b= max(a,b);
	if(a>b) _sign =-1;
	else _sign=1;
}

double integral::midpoint(int nstep){
	_sum=0.;
	_h= (_b -_a)/nstep;
	
	for(int i=0; i<nstep;++i){ //se parte da 1 va come O(h) e non O(h^2)
		double x= _a+ (i+0.5)*_h;
		_sum+= _integrand->Eval(x);
		
	}
	
	_integral = _sign*_sum*_h;
	return _integral;
}

double integral::simpson(int nstep){
	_sum=0.;
	double h1;
	_h= (_b -_a)/nstep;
	h1=_h/2;
	_sum=_integrand->Eval(_a)+_integrand->Eval(_b); //valuto la funzione negli estremi
	for(int i=1; i<2*nstep;i++){ 
		double x=_a+i*h1;
		if(i%2!=0){	
			_sum+=4*_integrand->Eval(x);
			}
		else if(i%2==0){
			_sum+=2*_integrand->Eval(x);
			}	
	}
	_integral = _sign*_sum*h1/3;
	return _integral;
}
