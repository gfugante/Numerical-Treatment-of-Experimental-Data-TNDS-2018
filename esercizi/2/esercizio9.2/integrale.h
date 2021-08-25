#ifndef _integrale_h_
#define _integrale_h_
#include "funzioneBase.h"
#include "Random.h"

class integrale{
	private:
		double _a,_b;
		double _sum;
		double _h;
		int _sign;
		double _integrale;
		funzioneBase *_integranda;
		Random _generatore;
	public:
		integrale(double a, double b, funzioneBase *funzione);
		double midpoint(int npassi);
		double simpson(int npassi);
		double montecarlo_media(int);
		double montecarlo_hit_or_miss(double, double);
		~integrale();
};

#endif
