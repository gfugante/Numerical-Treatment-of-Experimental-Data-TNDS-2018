#include <iostream>
#include <cmath>
#include "funzioneBase.h"
#include "seno.h"
#include "integrale.h"
#include "vettoredati.h"
#include "vettore.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
//#include "TH2F.h"

using namespace std;

int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
	TGraph * g=new TGraph();
	TGraph * g2=new TGraph();

	int j=0;

	funzioneBase * sin = new seno();
	integrale * integral = new integrale(0, M_PI, sin);
	double p, q;
	for(int i=0; i<9900; i++){
		q= integral->montecarlo_media(100+i);
		p= integral->montecarlo_hit_or_miss(100+i, 1);
		g->SetPoint(j, 100+i, q);
		g2->SetPoint(j, 100+i, p);
		j++;
	}
	TCanvas* c1=new TCanvas("c1", "c1", 1);
	c1->cd();
	g->GetXaxis()->SetTitle("N");
	g->GetYaxis()->SetTitle("Int");
	g->Draw("AL*");

	TCanvas* c2=new TCanvas("c2", "c2", 1);
	c2->cd();
	g2->GetXaxis()->SetTitle("N_HIT");
	g2->GetYaxis()->SetTitle("Int");
	g2->Draw("AL*");

	cout<<q<<endl;
	cout<<p<<endl;
	app.Run();
	return 0;
}
