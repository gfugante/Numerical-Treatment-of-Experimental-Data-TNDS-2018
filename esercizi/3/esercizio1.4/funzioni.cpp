#include "funzioni.hpp"
#include <cmath>
double Modulo(double x)
{
    double modulo;
    if(x>0)
    {
        modulo=x;
    }
    if(x<0)
    {
        modulo=-x;
    }
    return modulo;
}

double Modulo(double a, double b)
{
    double modulo;
    modulo=sqrt(pow(a,2)+pow(b,2));
    return modulo;
}

double Modulo(double *vettore, int dimensione)
{
    double modulo, conta=0;
    for(int i=0; i<dimensione; i++)
    {
        conta=conta+pow(vettore[i],2);
    }
    modulo=sqrt(conta);
    return modulo;
}
