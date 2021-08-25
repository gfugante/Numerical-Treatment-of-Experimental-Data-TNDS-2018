#ifndef _integrale_h_
#define _integrale_h_
#include "funzioneBase.h"

class integrale{
	private:
		double _a,_b;
		double _sum;
		double _h;
		int _sign;
		double _integrale;
		funzioneBase *_integranda;
		double _prec;
	public:
		integrale(double a, double b, funzioneBase *funzione);
		integrale(double a, double b, funzioneBase *funzione, double prec);
		double midpoint(int npassi);
		double simpson(int npassi);
		double trapezoidi(int npassi);
		double trapezoidiFissata();
		~integrale();
};

#endif
