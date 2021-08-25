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
	
	vettoredati v1(1000);
	vettoredati v2(1000);	

	int j=0;
	double integrale_vero=2;
	funzioneBase * sin = new seno();
	integrale * integral = new integrale(0, M_PI, sin);
	double p, q;
	for(int i=100; i<=10000; i=i+100){
		q= abs(integral->montecarlo_media(100+i)-integrale_vero);
		p= abs(integral->montecarlo_hit_or_miss(100+i, 1)-integrale_vero);
		v1.setComponenti(i, q);
		v2.setComponenti(i, p);
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

	cout<<"RMS= "<<v1.dev_st()<<endl;
	cout<<"RMS 2 = "<<v2.dev_st()<<endl;

	double q2=abs(integral->montecarlo_media(20000)-integrale_vero);
	double p2=abs(integral->montecarlo_media(2000000)-integrale_vero);
	
	double alpha=log(q/q2)/log(10000./20000.);
	double alpha2=log(p/p2)/log(10000./2000000.);

	double k=q*sqrt(10000);
	double k2=p*sqrt(10000);

	double N_ottimo=pow((k/0.001), 2);
	double N_ottimo2=pow((k2/0.001), 2);

	cout<<"alpha= "<<alpha<<endl;
	cout<<"alpha2= "<<alpha2<<endl;

	cout<<"N ottimo= "<<N_ottimo<<endl;
	cout<<"N ottimo 2= "<<N_ottimo2<<endl;

	app.Run();
	return 0;
}
