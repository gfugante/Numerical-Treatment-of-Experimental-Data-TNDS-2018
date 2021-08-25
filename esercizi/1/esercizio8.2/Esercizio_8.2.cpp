/*Questo programma che genera 100000 numeri casuali che seguono una distribuzione
esponenziale utilizzando il metodo della trasformata e altrettanti numeri casuali distribuiti
normalmente utilizzando il metodo Box-Muller. Nel caso della distribuzione esponenziale
assumere un parametro di rate ξ=0.1 mentre la gaussiana ha media μ=0 e σ=1.*/ 

#include "random.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <iostream>

using namespace std;

int main(int argc, char**argv){
	
	//Si generano 100000 numeri con Box-Muller e si riempie l'istogramma
	TApplication app("app", &argc, argv);
	
	Random rand(3);
	rand.setMu(0); 
	rand.setSigma(1);
	rand.setX0(-5); 
	rand.setX1(5);
	TH1F *h=new TH1F ("Numeri casuali1", "Distribuzione gaussiana utilizzando Box-Muller", 100,rand.getX0(),rand.getX1());

	
	for (int i=0; i<100000; i++){
		double n=rand.GaussBM();
		h->Fill(n);
		}
		
	//Si generano 100000 numeri con Box-Muller e si riempie l'istogramm
	rand.setLambda(0.1);
	TH1F *h2=new TH1F ("Numeri casuali2", "Distribuzione esponenziale", 100,0,50);
	for (int i=0; i<100000; i++){
		double n=rand.trasformataExp();
		h2->Fill(n);
		}
 
	//Disegnamo gli istogrammi
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
	
