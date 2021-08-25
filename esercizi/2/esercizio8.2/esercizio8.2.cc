#include <iostream>
#include <cmath>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "Random.h"

using namespace std;

int main(int argc, char ** argv){

	TApplication app("app", &argc, argv);
	Random gau(3);
	Random exp(3);

	gau.setA(1664525);
	gau.setC(1013904223);
	gau.setM(pow(2, 31));	
	exp.setA(1664525);
	exp.setC(1013904223);
	exp.setM(pow(2, 31));

	TH1F h("isto1", "istogramma1", 100, -5, 5);
	TH1F h2("isto1", "istogramma1", 100, -30, 30);

	for(int i=0; i<100000; i++){
		double n=gau.Box_Mull_Gauss(1,0);
		h.Fill(n);
		double n2=exp.trasformata_exp(-30,30);
		h2.Fill(n2);
	}
	TCanvas *c1 = new TCanvas("c1", "c1");
	c1->cd();
	h.Draw();
	TCanvas *c2 = new TCanvas("c2", "c2");
	c2->cd();
	h2.Draw();

	app.Run();
	return 0;
}
