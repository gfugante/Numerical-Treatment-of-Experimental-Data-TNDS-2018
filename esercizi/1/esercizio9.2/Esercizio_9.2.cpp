/*Studio dell'errore sul calcolo dell'integrale di sin(x) tra [0,π] in funzione del numero di punti utilizzati nel caso del metodo della media e del metodo hit-or-miss. Per fare questo si ripete per 1000 volte il calcolo dell'integrale con un numero di punti che varia tra 100 e 100000 ( in step da 100 punti ) e prendere RMS della distribuzione dei 1000 valori ottenuti.
Si fare un grafico dell'errore ottenuto in funzione del numero dei punti utilizzati per il calcolo dell'integrale.Si verificare che l'andamento dell'errore sia del tipo K Nα con α=0.5. Assumendo che l'andamento dell'errore sia noto ( del tipo k/ √N ) si determina poi quanti punti sono necessari per ottenere una precisione di 0.001. 
*/


#include "TApplication.h"
#include "TH1F.h" 
#include "TGraph.h"
#include "TPad.h"
#include "sin.h"
#include "integrator.h"
#include <iomanip>
#include "TCanvas.h"
#include <iostream>
#include"vettoredati.h" 
#define Nstep 100 //Numero di Punti che si prende come "step" per passare da Nin a Nfin
#define Nfin 10000//Numero di punti finale
#define Nin 100//numero di punti iniziale
#define N 100 //Numero di Step effettuati

using namespace std;

int main(int argc, char**argv){	

	Sin* sin=new Sin;
	int Ni=Nin;
	int n=Nfin/Nstep;
	double alphahom, alphamdm, errinhom, errinmdm,ihom,imdm, errinhom2, errinmdm2;
	int k=0;
	vettoreDati vmdm(N);
	vettoreDati vhom(N);
	integral integrale(0,M_PI, sin);
	TApplication app("App",&argc, argv);
 
	TGraph *gr1=new TGraph(); 
	TGraph *gr2=new TGraph(); 
	
	ihom=integrale.hitOrMiss(Ni); //Servono nel calcolo di Alfa
	imdm=integrale.metodoDellaMedia(Ni);
	errinhom=integrale.getErrorHoM();
	errinmdm=integrale.getErrorMdM();  
				
	while(Ni<=Nfin){
		for(int i=0;i<N;i++){
			vmdm.setComponent(i, integrale.metodoDellaMedia(Ni));//calcolo i valori dell'integrale da Nin fino ad arrivare a Nfin
			vhom.setComponent(i,integrale.hitOrMiss(Ni));
			}
		
		vmdm.devSt();//estraggo la deviazione standard dei valori calcolati con entrambi i metodi
		vhom.devSt();
		gr1->SetPoint(k,Ni,vmdm.getDevSt());//plotto i valori della deviazione standard ottenute in un grafico
		gr2->SetPoint(k,Ni,vhom.getDevSt());
		Ni+=Nstep;
		k++;
		}
	ihom=integrale.hitOrMiss(Nfin);
	imdm=integrale.metodoDellaMedia(Nfin);
	errinhom2=integrale.getErrorHoM();
	errinmdm2=integrale.getErrorMdM();
	
	TCanvas*c1=new TCanvas("c1", "c1", 1000,500);	
	c1-> Divide(2,1);
   
	TPad * p1=new TPad();
	TPad * p2=new TPad();

	c1->cd(1);
	p1->SetGrid();

	p1->Draw();
	p1->cd();

	gr1->GetXaxis()->SetTitle("Numero di punti");
	gr1->GetYaxis()->SetTitle("Errore");	
	gr1->SetTitle("Errore in funzione dei numeri di punti- Metodo della media");

	gr1->Draw("AP*");
	
	

	c1->cd(2);
	
	p2->SetGrid();
	p2->Draw();
	p2->cd();

	gr2->GetXaxis()->SetTitle("Numero di punti");

	gr2->GetYaxis()->SetTitle("Errore");	

	gr2->SetTitle("Errore in funzione dei numeri di punti-Hit or Miss");

	gr2->Draw("AP*");
	cout<<setprecision(3);
	alphahom=log(errinhom/integrale.getErrorHoM())/log(static_cast<double>(Nin)/Nfin);
	alphamdm=log(errinmdm/integrale.getErrorMdM())/log(static_cast<double>(Nin)/Nfin);	
	cout<<"Alpha stimato per il metodo hit or miss: "<<alphahom<<endl;
	cout<<"Alpha stimato per il metodo della media: "<<alphamdm<<endl;
	cout<<scientific;
	cout<<"Nmin stimato per il metodo hit or miss: "<<integrale.NminHoM(0.001)<<endl;
	cout<<"Nmin stimato per il metodo della media: "<<integrale.NminMdM(0.001)<<endl;

	


	app.Run(); 
	return 0;
}
	

