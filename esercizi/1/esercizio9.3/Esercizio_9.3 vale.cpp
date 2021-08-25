#include "TApplication.h"
#include "TH1F.h" 
#include "TCanvas.h"
#include "TGraph.h"
#include <iostream>
#include <cmath>
#include "integrator.h"
#define N 100
#define NPUNTI 100
#define NDIM 10 //numero delle n diverse dimensioni per la verifica del rapporto
using namespace std;

int main(int argc, char**argv){	
	//a,b estremi intervalloo in cui si integra, rhs raggio della ipersfera, lhc lato ipercubo, norma al quadrato, nc numero casuale generato(coordinata) sfx e la somma delle fxi(che vale sempre uno se sono all'interno della sfera)
	double a=-1, b=1, rhs=1, lhc=2, norma2=0, nc, sfx=0, vhs,vhc,vhsv; //volumi  hypersphere (vhs) e relativo per il cubo
	int npunti=1;
	Random r(2);
	integral integrale;
	 TApplication app("App",&argc, argv);
 	TH1F *h0=new TH1F ("nome0", "Andamento del rapporto tra vlume dell'ipersfera e dell'ipercubo", 100,0., M_PI);
	 TCanvas *c0 = new TCanvas("c0","puntiA",200,10,700,500);
	   c0->SetFillColor(00); 
	   c0->SetGrid();
	     
	   TH1F *hr = c0->DrawFrame(1,0.,NDIM,0.4); 
	   hr->SetXTitle("N "); //nomi degli assi
	   hr->SetYTitle("Errore ");
	   hr->SetTitle("Andamento del valore della deviazione standard al variare di N"); 
	
	TGraph *gr1=new TGraph(); 
 	for (int n=2; n<=NDIM; n++)
	{ 			//n numero delle dim che facciamo variare da due a 10 per vedere l'andamento del rapporto dei  volumi
		
		
		vhs=integrale.volumeIperSfera(n,NPUNTI,rhs);
		vhc=pow(lhc,n);

		gr1->SetPoint(n,n,vhs/vhc);
		sfx=0.;
		npunti=1;
	}
	
	gr1->SetMarkerColor(kBlue);

	gr1->Draw("*");
		
		
//parte 2 calcolo pecisione NON FUNGEEEEE
	vhsv=4/3*M_PI*rhs*rhs*rhs;

	vhs=integrale.volumeIperSfera(3,10000,rhs);
cout<<"La precisione con 10000 punti: "<<vhsv-vhs<<endl;
	vhs=integrale.volumeIperSfera(3,40000,rhs);
cout<<"La precisione con 40000 punti: "<<vhsv-vhs<<endl;
	vhs=integrale.volumeIperSfera(3,90000,rhs);
cout<<"La precisione con 90000 punti: "<<vhsv-vhs<<endl;
	vhs=integrale.volumeIperSfera(3,160000,rhs);
cout<<"La precisione con 160000 punti: "<<vhsv-vhs<<endl;
	
				
				
				

	app.Run(); 
	return 0;
}
	

