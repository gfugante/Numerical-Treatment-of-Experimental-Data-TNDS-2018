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
	Random gau2(3);

	gau.setA(1664525);
	gau.setC(1013904223);
	gau.setM(pow(2, 31));

	gau2.setA(1664525);
	gau2.setC(1013904223);
	gau2.setM(pow(2, 31));	

	TH1F h("isto1", "istogramma1", 100, -5, 5);
	TH1F h2("isto2", "istogramma2", 100, -5, 5);

	for(int i=0; i<100000; i++){
		double n=gau.Accept_Reject(1,1,-5,5);
		double n2=gau2.Accept_Reject(2,0,-10,10);
		h.Fill(n);
		h2.Fill(n2);
	}
	TCanvas *c1 = new TCanvas("c1", "c1");
	TCanvas *c2 = new TCanvas("c2", "c2");
	c1->cd();
	h.Draw();
	c2->cd();
	h2.Draw();

	app.Run();
	return 0;
}
