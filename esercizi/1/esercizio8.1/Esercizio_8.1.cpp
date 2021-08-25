/*Questo programma genera 100000 numericasuali con i parametri μ = σ = 1 e con μ=0,σ=2 e riempie due istogrammi con tali numeri.*/


#include "random.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <iostream>

using namespace std;

int main(int argc, char**argv){
	
	//Si generano 100000 numeri casuali con i parametri μ = σ = 1 e si riempie il primo istogramma.
	TApplication app("app", &argc, argv);
	Random rand(3);
	rand.setMu(1);
	rand.setSigma(1);
	TH1F *h=new TH1F ("Numeri casuali1", "Numeri casuali generati con una distribuzione gaussiana (metodo Accept-reject)", 100,rand.getX0(),rand.getX1());
	for (int i=0; i<100000; i++){
		double n=rand.Gauss();
		h->Fill(n);
		
		}
	//Si generano 100000 numeri casuali con i parametri μ=0 e σ=2 e si riempie il secondo istogramma
		rand.setMu(0);
		rand.setSigma(2);
		TH1F *h2=new TH1F ("Numeri casuali2", "Numeri casuali generati con una distribuzione gaussiana (metodo Accept-reject)", 100,rand.getX0(),rand.getX1());
	for (int i=0; i<100000; i++){
		double n=rand.Gauss();
		h2->Fill(n);
		
		}
	//Si disegnano gli istogrammi su due Canvas distinte
	TCanvas*c1=new TCanvas("c1", "c1");
	TCanvas*c2=new TCanvas("c2", "c2");
	c1->cd();
	h->Draw();
	h->GetXaxis()->SetTitle("Valore numerico");
	h->GetYaxis()->SetTitle("Frequenza");	
	c2->cd();
	h2->Draw();
	h2->GetXaxis()->SetTitle("Valore numerico");
	h2->GetYaxis()->SetTitle("Frequenza");	
	

	app.Run(); 
	return 0;
}
	
