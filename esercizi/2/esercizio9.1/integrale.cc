#include <iostream>
#include <algorithm>
#include <cmath>
#include "integrale.h"
#include "Random.h"
using namespace std;

integrale::integrale(double a, double b, funzioneBase * funzione):
	_generatore(3)
{
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

double integrale::montecarlo_media(int N){
	double sum=0;
	for(int j=0; j<N; j=j+100){
		for(int i=0; i<100; i++){
			double x=_generatore.uniforme(_a, _b);
			sum=sum+_integranda->eval(x);
		}
	}
	return _sign*sum/N*(_b-_a);
}		
	
double integrale::montecarlo_hit_or_miss(double N_HIT, double max){
	double N_TOT=0;
	double x, y;
	for(int j=0; j<N_HIT; j=j+100){
		for(int i=0; i<100; i++){
			do{
				x=_generatore.uniforme(_a, _b);
				y=_generatore.uniforme(0, max);
				N_TOT++;
			}while(y>_integranda->eval(x));
		}
	}
	double Area=(_b-_a)*max;
	return Area*(N_HIT/N_TOT);
}

integrale::~integrale() {}
