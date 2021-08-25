#ifndef _FUNZIONEBASE_H_
#define _FUNZIONEBASE_H_
#include <cmath>
#include <cfloat>
#include "vettore.h"
class funzioneBase{
	public:
		virtual double Eval(double x) const {;};
		virtual double Eval(vettore& x) const {;};

		//CAPIRE
		double Derivata(double x) const {double h = pow(DBL_EPSILON,0.2);
						return (Eval(x-2*h)-8*Eval(x-h)+8*Eval(x+h)-Eval(x+2*h))/(12*h);};

		double Derivata_Errore() const 	{return pow(DBL_EPSILON,0.8);};
		
};

#endif
