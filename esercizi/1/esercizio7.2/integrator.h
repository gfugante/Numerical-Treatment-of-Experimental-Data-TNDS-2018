#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_
//this class evaluate the integral given the extremes of integration and the pointer to a function
#include "funzionebase.h"

class integral {
	public:

		//costruttori
		integral(double a, double b, funzioneBase *function);
		integral(double a, double b, funzioneBase *function, double eps);

		//metodi per il calcolo dell'integrale
		double midpoint (int nstep);
		double simpson (int nstep);
		double trapezi ();

		//metodi 
		double getH()const{return _h;} //da' il passo dell'integrazione
		double getEPS()const{return _eps;}
		void setEPS(double eps){ _eps=eps;}
	
	
	
	private:
		double _a, _b;
		double _sum;
		double _h;
		int _sign;
		double _integral;
		funzioneBase *_integrand;
		double _eps;
};

#endif
