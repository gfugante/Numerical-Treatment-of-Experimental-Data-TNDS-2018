#ifndef _parabola_h_
#define _parabola_h_
#include "funzionebase.h"
class Parabola: public FunzioneBase {
public:
	Parabola();
	Parabola(double a, double b, double c);
	void SetA(double a){m_a=a;}
	void SetB(double b){m_b=b;}
	void SetC(double c){m_c=c;}
	double GetA() const {return m_a;}
	double GetB() const {return m_b;}
	double GetC() const {return m_c;}
	virtual double Eval(double x) const;
private:
	double m_a,m_b,m_c;
};
#endif
