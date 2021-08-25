#include <algorithm>
#include "integrale.h"
using namespace std;

integrale::integrale(double a, double b, funzioneBase * funzione){
	_integranda=funzione;
	_a=min(a,b);
	_b=max(a,b);
	if(a>b) _sign=-1;
	else _sign=1;
}

double integrale::midpoint(int npassi){
	_sum=0.;
	_h=(_b-_a)/npassi;
	
	for(int i=0; i<=npassi; i++){
		double x= _a+(i+0.5)*_h;
		_sum= _sum+_integranda->eval(x);
	}
	
	_integrale= _sign*_sum*_h;
	return _integrale;
}

double integrale::simpson(int npassi){
	_sum=0;
	_h=(_b-_a)/npassi;
	
	for(int i=0; i<=npassi; i++){
		double k;
		if(i==0 or i==npassi){
			k=1./3.;
		}
		else if((i%2)==0){
			k=2./3.;
		}else{
			k=4./3.;
		}
		double x=_a+(i*_h);
		_sum=_sum+k*_integranda->eval(x);
	}
	_integrale= _h*_sum*_sign;
	return _integrale;
}

integrale::~integrale() {}
