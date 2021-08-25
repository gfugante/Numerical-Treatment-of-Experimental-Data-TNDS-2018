#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_
//this class evaluate the integral given the extremes of integration and the pointer to a function
#include "funzionebase.h"
#include "random.h"
class integral {
	public:
		integral(double a, double b, funzioneBase *function);
		integral(double a, double b, funzioneBase *function, double eps);
		double midpoint (int nstep);
		double simpson (int nstep);
		double trapezi ();
		double getH()const{return _h;}
		double getEPS()const{return _eps;}
		void setEPS(double eps){ _eps=eps;}
	//INTEGRAZIONE MONTECARLO
		double hitOrMiss(unsigned int ntot);
		double metodoDellaMedia(unsigned int ntot); //manca parte sull'errore...da fare e come?
		double getErrorHoM()const{return _errorHoM;}
	
	
	
	private:
		double _a, _b;
		double _sum;
		double _h;
		int _sign;
		double _integral;
		funzioneBase *_integrand;
		double _eps;
	//INTEGRAZIONE MONTECARLO
		Random _generator;
		double _errorHoM;

};

#endif
