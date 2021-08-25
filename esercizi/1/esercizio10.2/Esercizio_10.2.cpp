/*Risoluzione del moto dell'oscillatore armonico con il metodo Runge-Kutta.
Per effettuare il grafico dell'errore, lanciare il programma piu' volte con diversi passi h e poi lanciare ./disegnaROOT (compilato a parte  con il comando make root). Il grafico dell'errore è relizzato utilizzando la scala log-log*/

#include "TApplication.h"
#include "TH1F.h" 
#include "TCanvas.h"
#include "TGraph.h"
#include<iostream>
#include<fstream>
#include<cmath>
#include "equazionidifferenziali.h"
#include "vettorelineare.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char**argv){
	if(argc!=2){
		cerr<<"Usage: "<<argv[0]<<" <passo_di_integrazione> "<<endl;
		return -1;
	}
	double h=atof(argv[1]);
	ofstream outfile;
	outfile.open("erroriRungeKutta.dat", ofstream::app); //si apre il file dove si salvano gli errori
	TApplication myApp("myApp",0,0);
	RungeKutta myRungeKutta;
	oscillatoreArmonico*osc=new oscillatoreArmonico(1.);
	double tmax=70;
	TGraph*posizione=new TGraph();
	TGraph*errore=new TGraph();
	int nstep=int(tmax/h+0.5);
	double t=0,err;
	vettoreLineare x(2); 
	x.setComponent(0,0.);//impostazione delle condizioni iniziali
	x.setComponent(1,1.);
	for(int i=0;i<nstep;i++){//i sta per il numero degli step
		posizione->SetPoint(i,t,x.getComponent(0));
		err=fabs(x.getComponent(0)-sin(osc->getOmega0()*t)); 
		//calcolo del punto successivo
		x=myRungeKutta.Passo(t,x,h,osc);
		t=t+h;
		}
	outfile<<h<<"\t"<<err<<endl;
	TCanvas*myCanvas=new TCanvas("c1", "c1");
	myCanvas->cd(1);
	posizione->GetXaxis()->SetTitle("t [s]");
	posizione->GetYaxis()->SetTitle("x [m]");	
	posizione->SetTitle("x(t) Oscillatore armonico, Runge-Kutta");				
	posizione->Draw("AL");
	myApp.Run();
	
	return 0;
}

