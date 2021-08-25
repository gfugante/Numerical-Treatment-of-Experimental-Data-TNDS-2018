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
	public:
		integrale(double a, double b, funzioneBase *funzione);
		double midpoint(int npassi);
		double simpson(int npassi);
		~integrale();
};

#endif
