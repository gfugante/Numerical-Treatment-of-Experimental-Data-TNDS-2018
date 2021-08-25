#ifndef integrale_hpp
#define integrale_hpp
#include "funzionebase.h"
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
};
#endif /* integrale_hpp */
