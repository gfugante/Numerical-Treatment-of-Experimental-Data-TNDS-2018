#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_
//this class evaluate the integral given the extremes of integration and the pointer to a function
#include "funzionebase.h"
#include "random.h"
#include <cmath>
#include <iostream>

class integral {
	public:
		integral(double a, double b, funzioneBase *function);
		integral(double a, double b, funzioneBase *function, double eps); //per usare metodo trapezi
		integral(funzioneBase* f, double xmin, double xmax, unsigned int n); //multidimensionali
		integral();
		double midpoint (int nstep);
		double simpson (int nstep);
		double trapezi ();
		double getH()const{return _h;}
		double getEPS()const{return _eps;}
		void setEPS(double eps){ _eps=eps;}
	//INTEGRAZIONE MONTECARLO
		double hitOrMiss(unsigned int ntot, double max); //nei vecchi va modificato il max della fz
		double HitOrMiss(unsigned int Npoints);
		double metodoDellaMedia(unsigned int ntot); 
		double getErrorHoM()const{return _errorHoM;}
		double getErrorMdM()const{return _errorMdM;}
		double NminHoM(double prec);
		double NminMdM(double prec);

		//integrale multiplo sfera
		double volumeIperSfera(int n, int npunti,double rhs);
	
	
	
	private:
		double _a, _b;
		double _sum;
		double _h;
		int _sign;
		double _integral;
		funzioneBase *_integrand;
		double _eps;
	//INTEGRAZIONE MONTECARLO
		unsigned int _n; // number of dimensions
		Random _generator;
		double _errorHoM; //monodimens
		double _errorMdM; //monodimens
		double _kHoM; //monodimens
		double _kMdM; //monodimens
};

#endif

