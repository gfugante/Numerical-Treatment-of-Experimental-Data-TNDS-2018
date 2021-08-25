#include <iostream>
#include "random.hpp"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "funzionebase.h"
#include <cmath>
#include "math.h"
#include "gaussiana.h"

using namespace std;

int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
    unsigned int a=1664525, c=1013904223, m=pow(2,31);
	int seed;
	cout<<"Inserisci il valore di partenza"<<endl;
	cin>>seed;
    Random rand(a,c,m,seed);
	Gaussiana *f=new Gaussiana(0,1);
	TH1F h("Istogramma", "Distribuzione gaussiana", 100, (f->GetMi()-5.*f->GetSigma()), (f->GetMi()+5.*f->GetSigma()));
    for(int i=0; i<100000; i++){ 
        double n= rand.BMGauss(f);
        h.Fill(n);
    }
    TH1F h2("Istogramma", "Distribuzione esponenziale", 100, 0, 10);
    double lambda=0.1;
    for(int i=0; i<100000; i++){
        double n= rand.TExp(lambda);
        h2.Fill(n);
    }
	TCanvas *c1=new TCanvas("c1", "c1");
    TCanvas *c2=new TCanvas("c2", "c2");
	c1->cd();
	h.Draw();
    c2->cd();
    h2.Draw();
	app.Run();
    return 0;
}

