#ifndef _SIN_H_
#define _SIN_H_
#include "funzionebase.h"
#include <cmath>
//this class evaluates the function sin(x) given x
class Sin : public funzioneBase{
	public:
		virtual double Eval(double x) const {return sin(x);}
	
	
};

#endif
