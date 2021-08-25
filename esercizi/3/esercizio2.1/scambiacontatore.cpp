#include "funzioni.hpp"
#include <iostream>

using namespace std;

int main()
{
    double a,b;
    cout<<"Inserisci i due valori da scambiare: "<<endl;
    cin>>a>>b;
    
    for(int i=0; i<10; i++)
    {
        scambiabyvalue(a,b);
    }
    
    for(int i=0; i<10; i++)
    {
        scambiabyreference(a,b);
    }
    
    for(int i=0; i<10; i++)
    {
        scambiabypointer(&a,&b);
    }
    
    cout<<"Numero di scambi globali e': "<<numeroScambi()<<endl;
    
    return 0;
}
