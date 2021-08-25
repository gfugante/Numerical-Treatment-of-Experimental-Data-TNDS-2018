#ifndef _PARABOLA_H_
#define _PARABOLA_H_
#include <iostream>
#include "funzioneBase.h"

using namespace std;

class parabola: public funzioneBase{
	public:
		parabola();
		parabola(double a, double b, double c);
		~parabola();
		virtual double eval(double x) const;
		void setA(double a);
		double getA();
		void setB(double b);
		double getB();
		void setC(double c);
		double getC();
	private:
		double _a, _b, _c;
};

#endif
