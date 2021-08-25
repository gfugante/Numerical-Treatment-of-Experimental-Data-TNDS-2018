#ifndef __Integrator_h__
#define __Integrator_h__

#include "FunzioneBase.h"

class Integral
{
	public:
		Integral(double a, double b, FunzioneBase *f);
		double midpoint (int nstep);
		double simpson (int nstep);
		double trapezoide (double eps);

	private:
		double _a, _b;
		double _sum;
		double _h;
		int _sign;
		double _integral;
		FunzioneBase *_integrand;
};

#endif
