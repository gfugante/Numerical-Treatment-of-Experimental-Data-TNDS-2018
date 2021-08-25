#ifndef _BISEZIONE_H_
#define _BISEZIONE_H_
#include "solutore.h"
#include "funzioneBase.h"
#include "meccquant.h"

using namespace std;

class bisezione: public solutore{
	public:
		bisezione();
		virtual double cercaZeri(double xmin, double xmax, double prec, const funzioneBase * f);
		~bisezione();
};

#endif
