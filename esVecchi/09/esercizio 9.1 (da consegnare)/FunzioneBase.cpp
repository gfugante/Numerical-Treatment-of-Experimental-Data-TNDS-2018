#include "FunzioneBase.h"
#include "Random.h"
#include <cmath>
#include <algorithm>


Parabola::Parabola(){
_a=0;
_b=0;
_c=0;
}

Parabola::Parabola(double a, double b, double c){
_a=a;
_b=b;
_c=c;
}

Parabola::~Parabola(){}



double Parabola::Eval(double x) const{
	return ((_a*(x*x))+(_b*x))+_c;
}



Seno::Seno(){
	_A=1;
	_omega=1;
	_phi=0;
}

Seno::Seno(double A, double omega, double phi){
	_A = A;
	_omega = omega;
	_phi = phi;
}

Seno::~Seno(){}

double Seno::Eval(double x) const{
	return _A*sin((_omega*x)+_phi);
}
	
double FunzioneBase::MaxRel (double a, double b, double eps)
{
	Random r(1);
	double y = r.Uniform(a, b);
	double x;
	double M = (a + b) / 2;

	double fmax = Eval(M);

	x = Eval(y);

	while (fabs(M - y) > eps)
	{
		if ( x >= fmax)
			M = y;
		
		y = r.Uniform(a, b);

		x = Eval(y);		
	}

	return M;
}






