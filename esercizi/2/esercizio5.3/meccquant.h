#ifndef _meccquant_h_
#define _meccquant_h_
#include <cmath>
#include "funzioneBase.h"

class meccquant: public funzioneBase{
	public:
		virtual double eval(double x) const {return sin(x)-(x*cos(x));}
};

#endif
