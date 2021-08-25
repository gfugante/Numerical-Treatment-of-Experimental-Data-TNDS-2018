#include <cmath>
#include "Random.h"

using namespace std;

Random::Random(int seme){
	_seme=seme;
	_a=1664525;
	_c=1013904223;
	_m=pow(2, 31);
}

void Random::setA(int a){
	_a=a;
}

void Random::setC(int c){
	_c=c;
}

void Random::setM(int m){
	_m=m;
}

double Random::Rand(){
	double n= (_a*_seme+_c)%_m;
	double d=n/(double)(_m-1);
	_seme=n;
	return d;
}

double Random::Accept_Reject(double sigma, double media, double A, double B){
	double x, y, g;
	do{
		double s=Rand();
		double t=Rand();
		x=A+(B-A)*s;
		y=(1/(pow((2*M_PI), 0.5)*sigma))*t;
		g=1/(pow((2*M_PI), 0.5)*sigma)*exp(-pow(x-media,2)/(2*sigma*sigma));
	}while(y>g);
	return x;
}

double Random::Box_Mull_Gauss(double sigma, double media){
		double s=this->Rand();
		double t=this->Rand();

		double x=sqrt(-2.*log(s))*cos(2*M_PI*t);

		return media+sigma*x;
}

double Random::Box_Mull_Exp(double rate){
		double z=this->Rand();

		double x=log(1-z);
		double p=-1./rate;

		return p*x;
}		

Random::~Random(){}
