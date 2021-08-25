#include <iostream>
#include <math.h>
#include "integrale.hpp"
#include "funzionebase.h"
#include "trigonometric.hpp"
#include <cmath>
#include <fstream>


using namespace std;
ofstream out;

int main() {
    double a=0;
    double b=M_PI;
	FunzioneBase *seno=new Seno();
    Integral *integrale=new Integral(a,b,seno);
    double risultato=2;
    out.open ("errore.txt");
    out<<"N:"<<"      "<<"Errore:"<<endl;
    for(int n=10; n<100001; n=n+10){
        double simpson=integrale->Simpson(n);
        out<<n<<"   "<<simpson-risultato<<endl;
    }
    out.close();
    return 0;
}
