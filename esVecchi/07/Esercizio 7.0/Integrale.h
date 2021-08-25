#ifndef __integrale__
#define __integrale__
#include "FunzioneBase.h"


class Integral{

private:
	double _a, _b;
	double _sum;
	double _h;
	double _integral;
	int _sign;
	FunzioneBase* _integrand;
	
public:
	Integral(double a, double b, FunzioneBase* function);
	double midpoint(int nstep);
	double simpson(int nstep);

};

#endif

