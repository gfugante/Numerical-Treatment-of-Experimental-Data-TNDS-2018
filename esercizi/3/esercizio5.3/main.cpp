#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include "bisezione.hpp"
#include "solutore.h"
#include "funzionebase.h"
#include "particulartrigonometric.h"

using namespace std;

int main(){
    FunzioneBase *f=new F(20);
    double a=M_PI,eps=10e-6;
    for(int i=1; i<21; i++){
        Bisezione A((i*a),(i*a+M_PI/2), eps, f);
        double zero=A.Cercazeri();
        cout<<"Lo zero n°"<<i<<" della funzione x=tanx è: ";
        cout<<fixed;
        cout<<setprecision(6)<<zero<<endl;
    }

}

/*
int main() {
    double a=M_PI,eps=10e-6;
    for(int i=1; i<21; i++){
        double zero=Bisezione((i*a),(i*a+M_PI/2), eps);
        cout<<"Lo zero n°"<<i<<" della funzione x=tanx è: ";
        cout<<fixed;
        cout<<setprecision(6)<<zero<<endl;
    }
}

double F(double x){
    return sin(x)-x*cos(x);
}

int Sign(double x){
    if (x>0) return 1;
    else return -1;
}


double Bisezione(double xmin, double xmax, double epsilon){
    double xmed;
    if(F(xmin)==0) return xmin;
    if(F(xmax)==0) return xmax;
    else{
        while(xmin-xmax>epsilon){
            xmed=xmin+(xmax-xmin)/2;
            if(F(xmed)==0) break;
            if(Sign(F(xmed))*Sign(F(xmin))<0) xmax=xmed;
            if(Sign(F(xmed))*Sign(F(xmax))<0) xmin=xmed;
        }
        return xmin+(xmax-xmin)/2;
    }
}
*/
