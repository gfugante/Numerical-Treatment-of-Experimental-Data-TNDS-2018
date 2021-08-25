#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_
//this class evaluate the integral given the extremes of integration and the pointer to a function
#include "funzionebase.h"

class integral {
	public:
		integral(double a, double b, funzioneBase *function);
		double midpoint (int nstep);
		double simpson (int nstep);
		double getH()const{return _h;}
	
	private:
		double _a, _b;
		double _sum;
		double _h;
		int _sign;
		double _integral;
		funzioneBase *_integrand;
};

#endif
