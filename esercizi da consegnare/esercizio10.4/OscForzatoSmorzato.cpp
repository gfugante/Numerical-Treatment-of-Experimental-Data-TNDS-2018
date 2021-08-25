#include "OscForzatoSmorzato.h"

const double g = 9.806;

OscForzatoSmorzato::OscForzatoSmorzato(double omega0, double omegaf, double alfa){
	_omega0 = omega0;
	_omegaf = omegaf;
	_alfa = alfa;
}

OscForzatoSmorzato::~OscForzatoSmorzato()
{ }

VettoreLineare OscForzatoSmorzato::Eval(double t, const VettoreLineare& x) const{
	VettoreLineare r(2);
	r.SetComponent(0, x.GetComponent(1));
	r.SetComponent(1, -pow(_omega0, 2) *  x.GetComponent(0) - _alfa * x.GetComponent(1) + sin(_omegaf * t) );
	
	return r;
}
