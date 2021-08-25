#include <cmath>
#include "Random.h"

using namespace std;

Random::Random(int seme){
	_seme=seme;
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
	double d=n/(_m-1);
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

Random::~Random(){}
