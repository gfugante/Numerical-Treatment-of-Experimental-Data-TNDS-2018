#include "random.hpp"
#include <cmath>
#include "math.h"
#include "gaussiana.h"
#include <iostream>

using namespace std;
Random::Random(unsigned int seed){
    _seed=seed;
}

double Random::Rand(){
    int rand=((_a*_seed+_c)%_m);
    _seed=rand;
    return (1.*rand)/(_m-1);
}

Random::Random(unsigned int a, unsigned int c, unsigned int m, unsigned int seed){
    _a=a;
    _c=c;
    _m=m;
    _seed=seed;
}

double Random::ARGauss(Gaussiana *f){
	double x,y;
	unsigned int p=_seed;
	do {
	double r1=Rand();
	double r2=Rand();
	double a=(f->GetMi())-5.*(f->GetSigma());
	double b=(f->GetMi())+5.*(f->GetSigma());
	double max=(1./(pow(2*M_PI,0.5)*(f->GetSigma())));
	x=a+(b-a)*r1;
	y=max*r2;
	}while(y>(f->Eval(x)));
	return x;
}

double Random::BMGauss(Gaussiana *f){
	double s=this->Rand();
	double t=this->Rand();
	double g=sqrt(-2*log(s))*cos(2*M_PI*t);
	return f->GetMi()+(f->GetSigma())*g;
}

double Random::TExp(double lambda){
    double r=this->Rand();
    double x=-1./(lambda)*log(1-r);
    return x;
}
