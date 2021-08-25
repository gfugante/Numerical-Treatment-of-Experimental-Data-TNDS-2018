#include "random.h"
#include<cmath>

double Random::Rand(){ //mi restituisce un valore tra 0 e 1
	int n1, n0;
	n0=_seed;
	n1=(_a*n0+_c)%_m;
	setSeed(n1);
	return 1.*n1/(_m-1);
	}

double Random::Gauss(){
	double s, t, a, b, x, y, max,fx;
	a=_x0;
	b=_x1;
	max=1/(_sigma*sqrt(2*M_PI)); 
	do{	
		double s=this->Rand();
		double t=this->Rand();
		x=a+(b-a)*s;
		fx=1/(_sigma*sqrt(2*M_PI))*exp(-pow((x-_mu),2)/(2*pow(_sigma, 2)));
		y=max*t;
	} while(y>fx);
	
	return x;
	}

double Random::GaussBM(){ //Metodo Box-Muller
	double s=this->Rand();
	double t=this->Rand();
	double g=sqrt(-2.*log(s))*cos(2*M_PI*t);
	return _mu+ _sigma*g;
}

double Random::trasformataExp (){
	double z=this->Rand();
	return -1/_lambda*log(1.00001-z); //perchè z può anche essere uguale a 1
	
}
	
