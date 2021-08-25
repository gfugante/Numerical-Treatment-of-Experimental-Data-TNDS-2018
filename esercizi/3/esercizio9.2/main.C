#include "funzionebase.h"
#include "integrale.hpp"
#include "random.hpp"
#include "trigonometric.hpp"
#include "math.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include "TApplication.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;
ofstream out;
int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
	FunzioneBase *S=new Seno(1,1);
	Integral H(0.,M_PI,S);
	int a=0;
	double HitMiss, Media, b=0, c=0;;
	double vRMS1[100], vRMS2[100];
	TGraph* HM=new TGraph();
	TGraph* M=new TGraph();
	for(int i=100; i<10001; i=i+100){
		for(int j=0; j<1000; j++){
			HitMiss=H.HM1(i,1.,0);
			Media=H.Media1(i);
			b=b+pow(HitMiss-2,2);
			c=c+pow(Media-2,2);
		}
		vRMS1[a]=sqrt(b/1000.);
		vRMS2[a]=sqrt(c/1000.);
		a=a+1;
		HM->SetPoint(a,i,sqrt(b/1000.));
		M->SetPoint(a,i,sqrt(c/1000.));		
		b=0;
		c=0;
	}
		//visto che l'errore va come k/radq(N), la precisione richiesta (0,001) si ottiene in N passi dove  N=k^2*10^6
	a=0;
	out.open("Errori.dat");
	out<<"RMS in funzione del numero di passi: Metodo Hit or Miss"<<endl;
	for(int i=100; i<10000; i=i+100){
		out<<i<<"   "<<vRMS1[a]<<endl;
		a=a+1;
	}
	a=0;
	out<<"RMS in funzione del numero di passi: Metodo Media"<<endl;
	for(int i=100; i<10000; i=i+100){
		out<<i<<"   "<<vRMS2[a]<<endl;
		a=a+1;
	}
	out<<"Stima del parametro alpha per il metodo HitorMiss e Media:  "<<endl;
	out<<log(vRMS1[10]/vRMS1[50])/log(1000./5000.)<<endl;
	out<<log(vRMS2[10]/vRMS2[50])/log(1000./5000.)<<endl;	
	out.close();
	cout<<log(vRMS1[10]/vRMS2[50])/log(1000./5000.);
	TCanvas* mycanvas=new TCanvas("2","");
	mycanvas->Divide(2,1);
	mycanvas->cd(1);
	HM->GetXaxis()->SetTitle("Metodo Hit or Miss, Numero di punti");
	HM->GetYaxis()->SetTitle("Errore");
	HM->Draw("AP*");
	mycanvas->cd(2);
	M->GetXaxis()->SetTitle("Metodo Media, Numero di punti");
	M->GetYaxis()->SetTitle("Errore");
	M->Draw("AP*");
	app.Run();
	return 0;
}
