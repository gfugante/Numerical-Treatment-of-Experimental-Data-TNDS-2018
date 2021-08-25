#include <iostream>
#include <cmath>

#include "TGraph.h" 
#include "TApplication.h" 
#include "TCanvas.h" 

#include "Integrale.h"
#include "FunzioneBase.h"
#include "TAxis.h"


using namespace std;

int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
	Seno* S = new Seno();
	Integral* I = new Integral(0.,M_PI,S);

	TGraph* g1 = new TGraph();
	TGraph* g2 = new TGraph();

	double y;
	int x;
	for(unsigned int i=1; i<1001; i++){

		x = i * 100;
		y = I->hitormiss(x, M_PI/2.);
		g1->SetPoint(i, x, y);
		
		y = I->media(x);
		g2->SetPoint(i, x, y);
	}

	TCanvas *c1 = new TCanvas("C1","C1",1);
	TCanvas *c2 = new TCanvas("C2","C2",2);
	
	c1->cd();
	g1->GetXaxis()->SetTitle("n.points [100 points]");
	g1->GetYaxis()->SetTitle("valori integrale");
	g1->Draw("AL");
	
	c2->cd();
	g2->GetXaxis()->SetTitle("n.points [100 points]");
	g2->GetYaxis()->SetTitle("valori integrale");
	g2->Draw("AL");
	
	app.Run();
	
	return 0;	
}
