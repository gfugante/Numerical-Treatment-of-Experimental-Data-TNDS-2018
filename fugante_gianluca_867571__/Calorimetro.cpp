#include "Calorimetro.h"


Calorimetro::Calorimetro(double T10, double T20){
	_T10 = T10;
	_T20 = T20;
	_K1 = 0.002;
	_K2 = 0.01;
}

Calorimetro::~Calorimetro()
{ }

VettoreLineare Calorimetro::Eval(double t, const VettoreLineare& x) const{
	VettoreLineare r(1);
	r.SetComponent(0, (_K1*_T20 + _K2*_T10) - x.GetComponent(0)*(_K1+_K2));
	
	return r;
}

