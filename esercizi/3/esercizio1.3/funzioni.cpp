#include "funzioni.hpp"
#include <cmath>
double somma(double vettore[], int limite)
{
    double somma=0;
    for (int i=0; i<limite; i++)
    {
        somma=somma+vettore[i];
    }
    return somma;
}

double sommaquadratura(double vettore[], int limite)
{
    double sommaq=0;
    for (int i=0; i<limite; i++)
    {
        sommaq=sommaq+(pow(vettore[i],2));
    }
    return sommaq;
}
