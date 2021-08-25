#include <iostream>
#include <fstream>
#include <cmath>
#include "funzioni.hpp"

using namespace std;
int Modulo(int x);

int main()
{
    ifstream input;
    double a, modulo1,modulo2, modulo3;
    double v[2];
    double *p;
    int n;
    
    cout<<"Inserisci il numero di cui calcolare il modulo: "<<endl;
    cin>>a;
    modulo1=Modulo(a);
    cout<<"Il modulo di "<<a<<" è: "<<modulo1<<endl;
    
    cout<<"Inserisci le 2 componenti del vettore di cui calcolare il modulo: "<<endl;
        for(int i=0; i<2; i++)
        {
            cin>>v[i];
        }
    modulo2=Modulo(v[0],v[1]);
    cout<<"Il modulo del vettore a 2 componenti è: "<<modulo2<<endl;
    
    input.open("dati.dat");
    input>>n;
    p=new double[n];
        for(int i=0; i<n; i++)
        {
            input>>p[i];
        }
    input.close();
    modulo3=Modulo(p, n);
    cout<<"Il modulo del vettore di "<<n<<" componenti è: "<<modulo3<<endl;
    
    return 0;
}
