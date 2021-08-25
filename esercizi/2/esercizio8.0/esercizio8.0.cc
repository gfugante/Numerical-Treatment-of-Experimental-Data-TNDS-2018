#include <iostream>
#include <cmath>
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "Random.h"

using namespace std;

int main(int argc, char ** argv){

	TApplication app("app", &argc, argv);
	Random ran(3);
	ran.setA(1664525);
	ran.setC(1013904223);
	ran.setM(pow(2, 31));	
	TH1F h("isto", "istogramma", 100, 0, 1);

	for(int i=0; i<100000; i++){
		double n=ran.Rand();
		h.Fill(n);
	}

	TCanvas *c1 = new TCanvas("c1", "c1");
	c1->cd();
	h.Draw();

	app.Run();
	return 0;
}
