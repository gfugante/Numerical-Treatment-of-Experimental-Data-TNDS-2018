#ifndef _PARABOLA_H_
#define _PARABOLA_H_
#include "funzionebase.h"

class parabola : public funzioneBase{
	public:
		parabola();
		parabola(double a,double b,double c);
		~parabola();
		virtual double Eval(double x) const;
		double getA() const { return _a;}
		double getB() const { return _b;}
		double getC() const { return _c;}
		void setA(double a){ _a=a; }
		void setB(double b){ _b=b; }
		void setC(double c){ _c=c; }
		
	private:
		double _a, _b, _c;
	
	
};#endif
