#ifndef __Integrator_h__
#define __Integrator_h__

#include "FunzioneBase.h"

class Integral
{
	private:
		double _a, _b;
		double _sum;
		double _h;
		int _sign;
		double _integral;
		FunzioneBase *_integrand;

	public:
		Integral(double a, double b, FunzioneBase *f);
		
		double Trapezoide (double eps);
		
};

#endif
