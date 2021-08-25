#include <iostream>
#include <cmath>

#include "TGraph.h" 
#include "TApplication.h" 
#include "TCanvas.h" 

#include "Integrale.h"
#include "FunzioneBase.h"
#include "TAxis.h"


using namespace std;

double media(double*, unsigned int);
double devst(double*, unsigned int);


int main(int argc, char** argv){

	TApplication app("app", &argc, argv);
	Seno* S = new Seno();
	Integral* I = new Integral(0.,M_PI,S);

	TGraph* g1 = new TGraph();
	TGraph* g2 = new TGraph();

	double y;
	int x;
	int H = 1000;

	double* val1 = new double[H];
	double* val2 = new double[H];

	for(unsigned int i=1; i<101; i++){
		x = i*100;
		for (unsigned int j=0; j<H; j++){			
			val1[j] = I->hitormiss(x, M_PI);
			val2[j] = I->media(x);
		}
		
		g1->SetPoint(i, x, devst(val1,H));
		g2->SetPoint(i, x, devst(val2,H));
	}
	delete []val1;
	delete []val2;
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


double media(double *v, unsigned int N){

	double sum = 0.;
	for(unsigned int i=0; i<N; i++) sum+=v[i];

	return sum/N;

}

double devst(double *v, unsigned int N){

	double Media = media(v,N);
	double sum = 0.;
	for(unsigned int i=0; i<N; i++) sum+=pow(v[i]-Media,2);

	return sqrt(sum/N);
}
