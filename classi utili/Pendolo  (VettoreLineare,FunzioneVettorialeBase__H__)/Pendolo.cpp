#include "Pendolo.h"

const double g = 9.806;

Pendolo::Pendolo(double l)
{
	_l = l;
}

Pendolo::~Pendolo()
{ }

VettoreLineare Pendolo::Eval(double t, const VettoreLineare& x) const
{
	VettoreLineare r(x.GetN());

	for (int i=0; i<(x.GetN()/2);i++){
		r.SetComponent(i, x.GetComponent(x.GetN() / 2 + i));
		r.SetComponent(i + x.GetN()/2, -g / _l * sin(x.GetComponent(i) ) );
	}
	return r;
}
