#include "TApplication.h"
#include "TF1.h"
#include "TGraph.h"
#include "sin.h"
#include "integrator.h"
#include "TH1F.h" 
#include "TCanvas.h"
#include <iostream>
#define Nstep 100
#define Nin 100
#define Nfin 10000


using namespace std;

int main(int argc, char**argv){	

	Sin* sin=new Sin;
	int n=Nfin/Nstep;
	double x[n];//vettore degli n
	double hom[n];//vettore con i valori dell-integrale
	double mdm[n];
	int k=1;
	integral integrale(0,M_PI, sin);
	 TApplication app("App",&argc, argv); 
		for(int i=Nin;i<=Nfin;i=i+Nstep){
			x[k-1]=i;
			hom[k-1]=integrale.hitOrMiss(i);
			mdm[k-1]=integrale.metodoDellaMedia(i);
			k++;
			}
			
		
	   TCanvas *c1 = new TCanvas("c1","c1",1000,100,1000,700);
		c1->Divide(1,2);
		
	
	TGraph *gr1=new TGraph(n, x, hom); 
	TGraph *gr2=new TGraph(n,x,mdm); 
	   
	  TPad * p1=new TPad();
	TPad * p2=new TPad();

	c1->cd(1);
	p1->SetGrid();

	p1->Draw();
	p1->cd();

	gr1->SetTitle("Andamento dell'integrale per il metodo Hit or miss");
	gr1->GetXaxis()->SetTitle("Numero di punti");
	gr1->GetYaxis()->SetTitle("Valore integrale della fuznione Sin(x) con x tra [0,pi]");

	gr1->Draw("AP*");
	
	

	c1->cd(2);
	
	p2->SetGrid();
	p2->Draw();
	p2->cd();

	
	gr2->SetTitle("Andamento dell'integrale per il metodo della media");
	gr2->GetXaxis()->SetTitle("Numero di punti");
	gr2->GetYaxis()->SetTitle("Valore integrale della fuznione Sin(x) con x tra [0,pi]");

	gr2->Draw("AP*");
		


	 
	app.Run();
	 
	return 0;
}
	
