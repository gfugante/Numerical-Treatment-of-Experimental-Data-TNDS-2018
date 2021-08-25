#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
#include "funzioni.hpp"

using namespace std;

int main()
{
    float a,b,senzaerr,conerr;
    int z=0,limite;
    
    //PUNTO 1
    cout<<"PUNTO 1"<<endl;
    a=0.3 - 0.2 - 0.1;
    cout<<scientific<<a<<endl;
    
    a=0.3 - (0.2 + 0.1);
    cout<<a<<endl;
    
    a=0.4 - 0.3 - 0.1;
    cout<<a<<endl;
    
    a=0.4 - (0.3 + 0.1);
    cout<<a<<endl;
    
    a=(1E15 + 1) - 1E15;
    cout<<a<<endl;
    
    a=(1E16 + 1) - 1E16;
    cout<<a<<endl;
    
    //PUNTO 2
    cout<<"PUNTO 2"<<endl;
    cout<<setw(10)<<"Valore x"<<setw(30)<<"fconerrore(x)"<<setw(30)<<"fmigliore(x)"<<endl;
    for (float x=1E0; x<=1E18; x=x*10)
    {
        a=sqrt(x+1);
        b=sqrt(x);
        senzaerr=1/(a+b);
        conerr=a-b;
        if(conerr==0 and z!=7)
        {
            limite=log10 (x);
            z=7;
        }
        
        cout<<setw(10) << setprecision(1) <<x<<setw(30) << setprecision(5)<<conerr<<setw(30)<<senzaerr<<endl;
    }
    
    //PUNTO 3
    cout<<"PUNTO 3"<<endl;
    double data[4]={4, 7, 13, 16};
    double M, V;
    M=(somma(data, 4))/4;
    
    cout<<"La media dei valori presenti sul vettore è: "<<fixed<<M<<endl;
    float sommaq=sommaquadratura(data, 4);
    
    V=4*((sommaq/4)-(pow(M,2)))/3;
    cout<<"La varianza dei valori presenti sul vettore è: "<<V<<endl;
    
    double hugenumber[4]={4+10e9, 7+10e9, 13+10e9, 16+10e9};
    M=(somma(hugenumber, 4))/4;
    
    cout<<"La media dei valori presenti sul successivo vettore è: "<<fixed<<M<<endl;
    sommaq=sommaquadratura(hugenumber, 4);
    
    V=4*((sommaq/4)-(pow(M,2)))/3;
    cout<<"La varianza dei valori presenti sul successivo vettore è: "<<V<<endl;
    
    //PUNTO 4
    cout<<"PUNTO 4"<<endl;
    cout<<"L'esponente x per cui (1Ex+1)-1Ex dà un risultato sbagliato (punto2) è: "<<limite<<endl;
    
    return 0;
}