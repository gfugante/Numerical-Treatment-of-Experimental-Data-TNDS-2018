/*Implementare la risoluzione dell'equazione del pendolo usando i metodi precedentemente implementati. Fare quindi un grafico del periodo di oscillazione e verificare che per angoli grandi le oscillazioni non sono più isocrone. 
Nel grafico del periodo la linea rossa rappresenta il periodo nell'ipotesi delle piccole*/

#include "TApplication.h"
#include "TH1F.h" 
#include "TCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include<iostream>
#include "equazionidifferenziali.h"
#include "vettorelineare.h"
#include <stdlib.h>
#define N 15 //numero di ampiezze e periodi che voglio plottare nel grafico del periodo

using namespace std;

int main(int argc, char**argv){
	if(argc!=2){
		cerr<<"Usage: "<<argv[0]<<" <passo_di_integrazione>"<<endl;
		return -1;
	}
	double h=atof(argv[1]);
	double PHI=-M_PI/4; //definisco l-ampiezza di oscillazione iniziale
	TApplication myApp("myApp",0,0);
	RungeKutta myRungeKutta;
	Eulero myEulero;
	pendolo*pen=new pendolo(1.);
	double tmax=30;

	TGraph*posizione1=new TGraph();
	TGraph*posizione2=new TGraph();
	TGraph*fasi1=new TGraph();
	TGraph*fasi2=new TGraph();

	int nstep=static_cast<int>(tmax/h)+1;
	double t=0;
	vettoreLineare theta1(2); //theta1 Eulero, theta2 Rk
	theta1.setComponent(0,PHI);
	theta1.setComponent(1,0.);
	vettoreLineare theta2(2); 
	theta2.setComponent(0,PHI);
	theta2.setComponent(1,0.);
	for(int i=0;i<nstep;i++){//i sta per il numero degli step
		posizione1->SetPoint(i,t,theta1.getComponent(0)); 
		posizione2->SetPoint(i,t,theta2.getComponent(0));
		fasi1->SetPoint(i,theta1.getComponent(0),theta1.getComponent(1)); 
		fasi2->SetPoint(i,theta2.getComponent(0),theta2.getComponent(1));
		//calcolo del punto successivo
		theta1=myEulero.Passo(t,theta1,h,pen);
		theta2=myRungeKutta.Passo(t,theta2,h,pen);
		t=t+h;
		}
	
	//Calcolo periodo usando Runge-Kutta
	double T,v,amp=PHI,Tteo;
	Tteo=2*M_PI/sqrt(pen->getG()/pen->getL());
	double step=PHI/N;
	TGraph*ta2=new TGraph(); //Grafico per i periodi e le ampiezze
	TGraph*tat2=new TGraph(); //Grafico pe il periodo teorico

	tat2->SetPoint(0,-amp,Tteo);
	for(int i=0;i<N;i++){
		theta2.setComponent(0,amp); //Si ripistinano le condizioni iniziali
		theta2.setComponent(1,0.);
		t=0;
	
		while (theta2.getComponent(1)>=0){
			v=theta2.getComponent(1);
			theta2=myRungeKutta.Passo(t,theta2,h,pen);
			t=t+h;
			}
		T=(t-h)-v*h/(theta2.getComponent(1)-v);
		T=2*T;
		ta2->SetPoint(i,-amp,T);
		amp-=step;
		
		
	} 
	tat2->SetPoint(1,-amp,Tteo);
	
	//Calcolo periodo usando Eulero
	amp=PHI;
	TGraph*ta1=new TGraph(); //Grafico per i periodi e le ampiezze
	TGraph*tat1=new TGraph(); //Grafico pe il periodo teorico

	tat1->SetPoint(0,-amp,Tteo);
	for(int i=0;i<N;i++){
		theta1.setComponent(0,amp); //Si ripistinano le condizioni iniziali
		theta1.setComponent(1,0.);
		t=0;
	
		while (theta1.getComponent(1)>=0){ //Si procede finchè la velocità non inverte di segno
			v=theta1.getComponent(1);
			theta1=myEulero.Passo(t,theta1,h,pen);
			t=t+h;
			}
		T=(t-h)-v*h/(theta1.getComponent(1)-v); //Si effettua l'interpolazione
		T=2*T;
		ta1->SetPoint(i,-amp,T);
		amp-=step;
		
		
	} 
	tat1->SetPoint(1,-amp,Tteo);
	

	//Grafichiamo tutto
	TCanvas*myCanvas=new TCanvas("c1", "c1", 1200,600);
	myCanvas->Divide(3,2);
	myCanvas->cd(1);
	posizione1->GetXaxis()->SetTitle("t [s]");
	posizione1->GetYaxis()->SetTitle("theta [rad]");	
	posizione1->SetTitle("Theta(t) Pendolo Eulero");				
	posizione1->Draw("AL");//linea continua
	myCanvas->cd(2);
	fasi1->GetXaxis()->SetTitle("theta [rad]");
	fasi1->GetYaxis()->SetTitle("v [rad/s]");	
	fasi1->SetTitle("Spazio delle fasi Eulero");				
	fasi1->Draw("AL");
	myCanvas->cd(3);
	ta1->GetXaxis()->SetTitle("Ampiezza [rad]");
	ta1->GetYaxis()->SetTitle("Periodo [s]");	
	ta1->SetTitle("Periodo in funzione dell'ampiezza - Eulero");				
	ta1->Draw("A*");
	tat1->SetLineColor(kRed);
	tat1-> Draw("same");

	myCanvas->cd(4);
	posizione2->GetXaxis()->SetTitle("t [s]");
	posizione2->GetYaxis()->SetTitle("theta [rad]");	
	posizione2->SetTitle("Theta(t) Pendolo Runge Kutta");				
	posizione2->Draw("AL");
	myCanvas->cd(5);
	fasi2->GetXaxis()->SetTitle("theta [rad]");
	fasi2->GetYaxis()->SetTitle("v [rad/s]");	
	fasi2->SetTitle("Spazio delle fasi Runge-Kutta");				
	fasi2->Draw("AL");
	myCanvas->cd(6);
	ta2->GetXaxis()->SetTitle("Ampiezza [rad]");
	ta2->GetYaxis()->SetTitle("Periodo [s]");	
	ta2->SetTitle("Periodo in funzione dell'ampiezza - Runge-Kutta");				
	ta2->Draw("A*");
	tat2->SetLineColor(kRed);
	tat2-> Draw("same");

	myApp.Run(); 
	return 0;
}

