#include "FunzioneBase.h"




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









