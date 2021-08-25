#include <iostream>
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
	pendolo * pen = new pendolo(1.);
	TGraph * periodo = new TGraph();
	TGraph * posizione = new TGraph();
	double tmax=70.;

	int nstep = int (tmax/h+0.5);
	double t=0.;
	
	VettoreLineare x(2);
	x.setComponenti(0, 0.);
	x.setComponenti(1,1.);
	for(int step=0; step<nstep; step++){
		posizione->SetPoint(step, t, x.getComponenti(0));
		x=rm.passo(t, x, h, pen);
		t=t+h;
	}
	
	double v;
	for(int i=1; i<30; i++){
		double A=0.1*i;
		t=0;
		h=0.1;
		x.setComponenti(0, -A);
		x.setComponenti(1, 0.);
		while(x.getComponenti(1) >= 0.){
			v=x.getComponenti(1);
			x=rm.passo(t, x, h, pen);
			t=t+h;
		}
		double T=t-(h*x.getComponenti(1)/(x.getComponenti(1)-v));
		T=T*2;
		periodo->SetPoint(i, A, T);
	}

	TCanvas myCanvas("es 10.3", "posizione");
	posizione->GetXaxis()->SetTitle("t[s]");
	posizione->GetYaxis()->SetTitle("x[m]");
	posizione->Draw("ALP");
	
	TCanvas myCanvas2("es 10.3", "periodo");
	periodo->GetXaxis()->SetTitle("A[rad]");
	periodo->GetYaxis()->SetTitle("periodo[s]");
	periodo->Draw("AP*");

	myApp.Run();
	
	myCanvas.Close(), myCanvas2.Close();

	delete periodo;
	delete posizione;
	delete pen;
	return 0;
}
