#include "integrale.hpp"
#include "funzionebase.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include "random.hpp"
using namespace std;

Integral::Integral(double a, double b, FunzioneBase *function){
    _integrand=function;
    _a=min(a,b);
    _b=max(a,b);
    if(a>b) _sign=-1;
    else _sign=1;
}

double Integral::MidPoint(int nsteps){
    double x;
    _sum=0;
    _h=(_b-_a)/nsteps;
    for (int i=0; i<nsteps; i++){
        x=_a+(i+0.5)*_h;
        _sum=_sum+_integrand->Eval(x);
    }
    _integral=_sign*_sum*_h;
    return _integral;
}

double Integral::Simpson(int nsteps){
	double x,y;
	_h=(_b-_a)/nsteps;
	_sum=(_integrand->Eval(_a))*(1./3.)+(_integrand->Eval(_b))*(1./3.)+(_integrand->Eval(_a+_h))*(4./3.);
	for (int i=3; i<nsteps; i=i+2) {
		x=_a+i*_h;
		y=_a+(i-1)*_h;
		_sum=_sum+(_integrand->Eval(x))*(2./3.)+(_integrand->Eval(y))*(4./3.);
	}
	_integral=_sign*_sum*_h;
	return _integral;
}

double Integral::Trapezoidi(int nsteps){
	double x;
	_h=(_b-_a)/nsteps;
	_sum=(_integrand->Eval(_a))*(1./2.)+(_integrand->Eval(_b))*(1./2.);
	for (int i=1; i<nsteps; i++) {
		x=_a+i*_h ;
		_sum=_sum+(_integrand->Eval(x));
	}
	_integral=_sign*_sum*_h;
	return _integral;
}

double Integral::TrapezoidiFixed(double prec){
	double x;
	_sum=(_integrand->Eval(_a))*(1./2.)+(_integrand->Eval(_b))*(1./2.);
	double Iprec=0;
	double n=1;
	_integral=_sum*(_b-_a);
	
	do 	{
		for(int i=1; i<pow(2,n); i=i+2){
			_sum=_sum+_integrand->Eval(_a+i*(_b-_a)/(pow(2,n)));
		}
		Iprec=_integral;
		_integral=_sum*(_b-_a)/(pow(2,n));
		n++;
	}while(fabs(_integral-Iprec)>prec);
	
	return _integral;
}	

double Integral::HM1(double N, double max, double min){
	int nmiss=0;
	Random *R=new Random();
	for(int i=0; i<N;){	
		double r1=R->Rand();
		double r2=R->Rand();
		double x=_a+(_b-_a)*r1;
		double y=r2*(max-min);
		if(_integrand->Eval(x)>=0){
			if(y<_integrand->Eval(x) and y>=0){
				i++;
			}
			else{
				nmiss=nmiss+1;
			}
		if(_integrand->Eval(x)<0)
			if(y>_integrand->Eval(x) and y<=0){
				i++;
			}
			else{
				nmiss=nmiss+1;
			}
		}
	}
	
	double ntot=nmiss+N;
	_integral=(_b-_a)*(max-min)*(N/ntot);
	return _integral;
}

double Integral::Media1(int N) {
	Random *R=new Random();
	double sum=0;
	for(int i=0; i<N; i++){
		double r1=R->Rand();
		double x=_a+(_b-_a)*r1;
		sum=sum+_integrand->Eval(x);
	}
	double n=N;
	_integral=(1/n)*sum*(_b-_a);
	return _integral;
}
