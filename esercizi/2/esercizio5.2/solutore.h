#ifndef _SOLUTORE_H_
#define _SOLUTORE_H_
#include "funzioneBase.h"
#include "parabola.h"

class solutore{
	protected:
		double _a, _b;
		double _prec;
		const funzioneBase * _f;
	public:
		virtual double cercaZeri(double xmin, double xmax, double prec, const funzioneBase * f) =0;
		void setPrecisione(double epsilon) {_prec=epsilon;};
		double getPrecisione() {return _prec;};
};		

#endif
