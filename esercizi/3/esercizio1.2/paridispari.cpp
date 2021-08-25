#include <iostream>
#include <fstream>
#include "funzioni.hpp"

using namespace std;

int main()
{
    int N=Conta();
    double* p=new double[N];
    Carica(p,N);
    ScambioPD(p,N);
    Stampa(p,N);
    return 0;
}
