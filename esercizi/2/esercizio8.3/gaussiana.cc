#include "funzioneBase.h"
#include "gaussiana.h"
#include <cmath>
#include "math.h"

gaussiana::gaussiana(double mi, double sigma) {
	_mi=mi;
	_sigma=sigma;
	}
double gaussiana::Eval(double x) const {
	return (1./(_sigma*pow(2*M_PI,0.5))*exp(-(pow(x-_mi,2))/(2*pow(_sigma,2))));
}
