#include "trigonometric.hpp"
#include "funzionebase.h"
#include <cmath>

Seno::Seno(){
	_a=1;
	_b=1;
}

Seno::Seno(double a, double b){
    _a=a;
    _b=b;
}

double Seno::Eval(double x) const{
    return (_a*sin(_b*x));
}

Coseno::Coseno(double a, double b){
    _a=a;
    _b=b;
}

double Coseno::Eval(double x) const{
    return (_a*cos(_b*x));
}
