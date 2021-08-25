#include <algorithm>
#include <iostream>
#include <cmath>
#include "integrale.h"
using namespace std;

integrale::integrale(double a, double b, funzioneBase * funzione){
	_integranda=funzione;
	_a=min(a,b);
	_b=max(a,b);
	if(a>b) _sign=-1;
	else _sign=1;
}

integrale::integrale(double a, double b, funzioneBase * funzione, double prec){
	_integranda=funzione;
	_a=min(a,b);
	_b=max(a,b);
	if(a>b) _sign=-1;
	else _sign=1;
	_prec=prec;
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
	_sum=0.;
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
double integrale::trapezoidi(int npassi){
	double x;
	_h=(_b-_a)/npassi;
	_sum=(_integranda->eval(_a))*(1./2.)+(_integranda->eval(_b))/(1./2.);
	for(int i=1; i<npassi; i++){
		x=_a+i*_h;
		_sum=_sum+(_integranda->eval(x));
	}
	_integrale=_sign*_sum*_h;
	return _integrale;
}

double integrale::trapezoidiFissata(){

	_sum=(_integranda->eval(_a)+_integranda->eval(_b))/2.;
	double I0=0;
	_sum=_sum+_integranda->eval((_a+_b)/2.);
	_integrale=_sum*(_b-_a)/2.;
	int n=2;
	while(fabs(I0-_integrale)>_prec){
		I0=_integrale;
		for(int m=1; m<pow(2, n); m=m+2){
			double q= _integranda->eval((m*(_b+_a)/(pow(2,n))));
			_sum=_sum+q;
		}
		_integrale=_sum*(_b-_a)/(pow(2,n));
		n++;
	}
	return _integrale;
}

integrale::~integrale() {}
