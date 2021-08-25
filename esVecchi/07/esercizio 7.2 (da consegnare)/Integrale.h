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
	double _prec;
	FunzioneBase* _integrand;
	
public:
	Integral(double a, double b, FunzioneBase* function);
	Integral(double a, double b, double prec, FunzioneBase* function);
	double trapezi();
	double midpoint(int nstep);
	double simpson(int nstep);
	double getIntegral(){return _integral;};
};

#endif

