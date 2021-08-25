#include <iostream>
#include <cmath>
#include <cstdlib>
#include "equazioniDifferenziali.h"
#include "VettoreLineare.h"
#include "vettore.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"

using namespace std;

int main(int argc, char** argv){
	if(argc!=2){
		cerr<<"Usage: "<< argv[0]<<"passo di integrazione"<<endl;
		exit (-1);
	}

	double h=atof(argv[1]);
	TApplication myApp("myApp", 0, 0);
	Runge_Kutta rm;
	oscillatore_armonico * osc = new oscillatore_armonico(1.);
	double tmax=70.;
	TGraph * posizione = new TGraph();
	TGraph * errore = new TGraph();

	int nstep = int (tmax/h+0.5);
	double t=0.;
	
	VettoreLineare x(2);
	x.setComponenti(0,0.);
	x.setComponenti(1,1.);

	for(int step=0; step<nstep; step++){
		posizione->SetPoint(step, t, x.getComponenti(0));
		errore->SetPoint(step, t, x.getComponenti(0)-sin(t));
		x=rm.passo(t, x, h, osc);
		t=t+h;
	}

	TCanvas *myCanvas = new TCanvas();
	myCanvas->Divide(1,2);
	
	myCanvas->cd(1);
	posizione->Draw("AL");
	posizione->GetXaxis()->SetTitle("t[s]");
	posizione->GetYaxis()->SetTitle("x[m]");
	
	myCanvas->cd(2);
	errore->Draw("AL");
	errore->GetXaxis()->SetTitle("t[s]");
	errore->GetYaxis()->SetTitle("errore[m]");

	myApp.Run();

	delete posizione;
	delete errore;
	delete osc;
	return 0;
}
