#ifndef _seno_h_
#define _seno_h_
#include <cmath>
#include "funzioneBase.h"

class seno: public funzioneBase{
	public:
		virtual double eval(double x) const {return sin(x);}
};

#endif
