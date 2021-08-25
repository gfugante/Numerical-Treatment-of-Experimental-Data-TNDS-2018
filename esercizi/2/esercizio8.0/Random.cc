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

Random::~Random(){}
