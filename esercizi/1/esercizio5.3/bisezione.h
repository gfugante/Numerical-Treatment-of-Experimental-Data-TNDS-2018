#ifndef _BISEZIONE_H
#define _BISEZIONE_H_
#include "signfunction.h"
#include <cmath>
#include <iostream>
#include "solutore.h"

using namespace std;

class bisezione:public solutore {
	public:
	bisezione(); //setta solo la precisione
	bisezione(double prec, double xmin, double xmax);
	bool getBoolean() const { return _zero;}
	void setFalse(){_zero=false;}
	virtual double cercaZeri(double xmin, double xmax, const funzioneBase* f);

	private:
	bool _zero; //mi dice se ha trovato uno zero
	};

#endif
