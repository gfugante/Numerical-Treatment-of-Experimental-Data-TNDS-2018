#include <iostream>
#include "random.hpp"
#include <cmath>
#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

using namespace std;

int main(int argc, char** argv){
    TApplication app("app", &argc, argv);
	unsigned int a=1664525, c=1013904223, m=pow(2,31);
    int p, N, q;
    double sum=0;
    cout<<"Inserisci il valore di partenza"<<endl;
    cin>>p;
    cout<<"Inserisci il numero N di numeri casuali da generare"<<endl;
    cin>>N;
    cout<<"Inserisci il numero q su cui fare le somme"<<endl;
    cin>>q;
    int count=0, dim=N/q, pos=0;
    double *v=new double[dim];
    Random R(a,c,m,p);
    TH1F h1("Istogramma", "Distribuzione uniforme numeri casuali [0;1]", 100, 0, 1);
    TH1F h2("Isogramma", "Distribuzione somme", 100, 0,q);
    while(count<=(N-q)){
        for(int i=0; i<q; i++){
            double t=R.Rand();
            sum=sum+t;
            h1.Fill(t);
            p=t;
        }
        v[pos]=sum;
        pos++;
        sum=0;
        count=count+q;
    }
    for(int i=0; i<dim; i++){
        h2.Fill(v[i]);
    }
    TCanvas *c1=new TCanvas("c1", "c1");
    TCanvas *c2=new TCanvas("c2", "c2");
    c1->cd();
    h1.Draw();
    c2->cd();
    h2.Draw();
    app.Run();
    return 0;
}
