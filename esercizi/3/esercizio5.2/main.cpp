#include <iostream>
#include <cmath>
#include <iomanip>
#include "funzionebase.h"
#include "parabola.h"
#include "bisezione.hpp"
#include "solutore.h"

using namespace std;

int main(){
    double a, b, eps;
    cout<<"Inserisci gli estremi dell'intervallo in ordine crescente entro il quale cercare lo zero della funzione y=3x^2+5x-2: "<<endl;
    cin>>a>>b;
    cout<<"Inserisci la precisione entro la quale calcolare lo zero della funzione: "<<endl;
    cin>>eps;
    FunzioneBase *F=new Parabola(3,5,-2);
	cout<<"prova1"<<endl;
    Bisezione A(a,b,eps,F);
    	cout<<"prova2"<<endl;
        int cifresignificative=-log10(eps);
        double zero=A.Cercazeri();
        cout<<"Lo zero della funzione è: ";
        cout<<fixed;
        cout<<setprecision(cifresignificative)<<zero;
    return 0;
}
