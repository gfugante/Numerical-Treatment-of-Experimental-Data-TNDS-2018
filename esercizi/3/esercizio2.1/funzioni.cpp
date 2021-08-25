#include "funzioni.hpp"
#include <iostream>
using namespace std;

int Nscambi=0;

int numeroScambi() {
    return Nscambi;
}

void scambiabyvalue(double a, double b)
{
    static int Ns=0;
    double c;
    c=a;
    a=b;
    b=c;
    Ns++;
    Nscambi++;
    cout<<"Numero di scambi per valore "<<Ns<<endl;
}

void scambiabyreference(double &a, double &b)
{
    static int Ns=0;
    double c;
    c=a;
    a=b;
    b=c;
    Ns++;
    Nscambi++;
    cout<<"Numero di scambi per referenza "<<Ns<<endl;
}

void scambiabypointer(double *a, double *b)
{
    static int Ns=0;
    double c;
    c=*a;
    *a=*b;
    *b=c;
    Ns++;
    Nscambi++;
    cout<<"Numero di scambi per puntatore "<<Ns<<endl;
}
