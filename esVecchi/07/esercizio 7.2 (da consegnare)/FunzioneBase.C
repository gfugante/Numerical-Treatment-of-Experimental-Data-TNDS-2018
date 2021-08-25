#include "FunzioneBase.h"
#include <cmath>



Parabola::Parabola(){
_a=0;
_b=0;
_c=0;
}

Parabola::Parabola(double a, double b, double c){
_a=a;
_b=b;
_c=c;
}

Parabola::~Parabola(){}



double Parabola::Eval(double x) const{
	return ((_a*(x*x))+(_b*x))+_c;
}



Seno::Seno(){
	_A=1;
	_omega=1;
	_phi=0;
}

Seno::Seno(double A, double omega, double phi){
	_A = A;
	_omega = omega;
	_phi = phi;
}

Seno::~Seno(){}

double Seno::Eval(double x) const{
	return _A*sin((_omega*x)+_phi);
}
	







