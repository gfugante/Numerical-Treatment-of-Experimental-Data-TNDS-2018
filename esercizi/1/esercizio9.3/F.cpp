#include "F.h"

double F::Eval(vettore& x) const { //funzione caratteristica
	double raggio;
	double sum = 0.;
	for (int i=0; i<x.getN(); i++) 
		{sum += x.getComponent(i)*x.getComponent(i);}
	raggio = pow(sum , 0.5);
	if ( raggio <= 1 ) { return 1; }
	if ( raggio >  1 ) { return 0; }			
};

double VolumeIpersfera(int n, double r) { //teorico
	return pow(M_PI,n*.5)*pow(r,n)/tgamma(n*.5+1);
}
