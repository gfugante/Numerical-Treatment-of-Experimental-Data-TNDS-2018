#include <iostream>
#include "random.hpp"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <cmath>

using namespace std;

int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
    unsigned int a=1664525, c=1013904223, m=pow(2,31);
    Random rand1(a,c,m,13);
	TH1F h("Istogramma", "Distribuzione uniforme periodo ampio", 100, 0, 1);
    for(int i=0; i<100001; i++){ //Range più ampio, periodo maggiore
        double n=rand1.Rand();
		h.Fill(n);
    }
    
  /*  TH1F h2("Isogramma", "Distribuzione uniforme periodo limitato", 100, 0, 1);
    Random rand2(4,1,9,4);
    for(int i=0; i<100001; i++){ //Range più ampio, periodo maggiore
        double n=rand1.Rand();
        h2.Fill(n);
    }*/
    TCanvas *c1=new TCanvas("c1", "c1");
   // TCanvas *c2=new TCanvas("c2", "c2");
    c1->cd();
    h.Draw();
    //c2->cd();
   // h.Draw();
	app.Run();
    return 0;
}
