#include <cmath>

#include "Modulo.h"


double modulo (double n) //restituisce valore assoluto di un numero
{
	if (n < 0)
		return -n;
	else
		return n;
}
//************************************************************
double modulo (double x, double y)
{
	return sqrt( pow(x,2) + pow(y,2) );
}
//************************************************************
double modulo (double *p, int N)
{
	double sumq = 0;


	for (unsigned int i = 0; i < N; i++)
		sumq += pow(p[i],2);

	return sqrt(sumq);
}
