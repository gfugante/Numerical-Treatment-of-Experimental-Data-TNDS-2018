#ifndef integrale_hpp
#define integrale_hpp
#include "funzionebase.h"
#include "random.hpp"
class Integral{
private:
    double _a, _b, _sum, _h;
    int _sign;
    double _integral;
    FunzioneBase *_integrand;
public:
   	Integral(double a, double b, FunzioneBase *function);
 	double MidPoint(int nsteps);
    double Simpson(int nsteps);
	double Trapezoidi(int nsteps);
	double TrapezoidiFixed(double prec);
	double HM1(double N, double max, double min);
	double Media1(int N);
};
#endif /* integrale_hpp */
