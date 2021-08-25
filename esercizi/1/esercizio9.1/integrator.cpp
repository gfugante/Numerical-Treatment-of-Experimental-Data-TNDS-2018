#include "integrator.h"
#include <algorithm>
#include <cmath>


using namespace std;

integral::integral(double a, double b, funzioneBase* function):_generator(1){
	_integrand = function;
	_a= min(a,b);
	_b= max(a,b);
	_eps=1.;// cosa combinarci 
	if(a>b) _sign =-1;
	else _sign=1;
}

integral::integral(double a, double b, funzioneBase* function, double eps):_generator(1){
	_integrand = function;
	_a= min(a,b);
	_b= max(a,b);
	_eps=eps;
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

double integral::trapezi (){
	double integral1,xm,xmh;
	_sum=(_integrand->Eval(_a)+_integrand->Eval(_b))/2;
	_integral=_sum*(_b-_a);
	xm=(_b+_a)/2;
	_sum=_sum+_integrand->Eval(xm);
	_h=(_b-_a)/2;
	integral1=_sum*_h;

	double e=4/3*abs((_integral-integral1)); 
	int i=2;
		while(e>_eps){
			_integral=integral1;
			_h=_h/2;
			xm=_a+_h;
			_sum=_sum+_integrand->Eval(xm);
			for(int j=1;j<pow(2,i-1);j++){
				xmh=xm+j*2*_h;
				_sum=_sum+_integrand->Eval(xmh);
			}
			integral1=_sum*_h;
			e=4/3*abs((_integral-integral1));
			i++;
		}
	 _integral=integral1;
	return integral1; 
		
}
	
double integral::hitOrMiss (unsigned int ntot){
	double max=1.; //MODIFICARE OGNI VOLTA, DIPENDE DALLA FZ
	double A=(_b-_a)*max;
	int ncount=0;
	double phit;
	double x,y,yv;

	for(int i=0;i<ntot; i++){
		 x=_a+(_b-_a)*_generator.Rand();
		 y=_generator.Rand()*max;
		 yv=_integrand->Eval(x);
	 
		if(yv<y){
			i--;
		}
		ncount++;
		
	}
	_integral=A*ntot/ncount;
	phit=_integral/A;
	_errorHoM=A*sqrt((phit*(1-phit))/ntot);
	return _integral;
}

double integral::metodoDellaMedia(unsigned int ntot){
	double sum=0.;
	
	for(int i=0;i<ntot; i++){
		double x=_a+(_b-_a)*_generator.Rand();
		sum+=_integrand->Eval(x);
		
		}
	 
	_integral=sum/ntot*(_b-_a);
 
	return _integral;	
		
}








	
