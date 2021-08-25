/*Implementare la risoluzione dell'equazione di un oscillatore armonico smorzato con forzante. Fare quindi un grafico della soluzione stazionaria in funzione della frequenza dell'oscillatore, ricostruendo la curva di risonanza.*/
#include "TApplication.h"
#include "TH1F.h" 
#include "TCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include<iostream>
#include "equazionidifferenziali.h"
#include "vettorelineare.h"
#include <stdlib.h>
#define N 20 //numero delle ampiezze che voglio plottare nel grafico della risonanza

using namespace std;

int main(int argc, char**argv){
	if(argc!=2){
		cerr<<"Usage: "<<argv[0]<<" <passo_di_integrazione>"<<endl;
		return -1;
	}
	double h=atof(argv[1]);
	double tmax=30;
	int nstep=static_cast<int>(tmax/h)+1;
	double t=0;

	TApplication myApp("myApp",0,0);
	RungeKutta myRungeKutta;
	Eulero myEulero;
	TGraph*posizione1=new TGraph();
	TGraph*posizione2=new TGraph();
	TGraph*fasi1=new TGraph();
	TGraph*fasi2=new TGraph();

	oscillatoreForzato*oscf=new oscillatoreForzato(10., 1./30., 10.);
	vettoreLineare x1(2);//Si impostano le condizioni iniziali (x1 si riferisce ad Eulero, x2 a Runge-Kutta)
	vettoreLineare x2(2); 
	x1.setComponent(0,0.);
	x1.setComponent(1,0.);
	x2.setComponent(0,0.);
	x2.setComponent(1,0.);
	for(int i=0;i<nstep;i++){//i sta per il numero degli step
		posizione1->SetPoint(i,t,x1.getComponent(0)); 
		posizione2->SetPoint(i,t,x2.getComponent(0));
		fasi1->SetPoint(i,x1.getComponent(0),x1.getComponent(1)); 
		fasi2->SetPoint(i,x2.getComponent(0),x2.getComponent(1));
		//calcolo del punto successivo
		x1=myEulero.Passo(t,x1,h,oscf);
		x2=myRungeKutta.Passo(t,x2,h,oscf);
		t=t+h;
		}

	//Calcolo dell'ampiezza Runge-Kutta:portiamo avanti l'integrazione per un tempo abbastanza lungo affinchè l'ampiezza delle oscillazioni si stabilizzi e, troviamo la massima x portando avanti l'integrazione per un tempo abbastanza lungo dopo aver raggiunto la condizione di stazionarieta'.
 	
	double semiamp,amp,win,step,v,max=0,ts;
	//omega iniziale, vale pero' se w0 e' maggiore di 1
	win=oscf->getW0()-1;
	oscf->setW(win); // altrimenti la frequenza di inizio e quella di risonanza
	step=2./N;//perche' si vuole variare w forzante da wo-1 a wo+1
	TGraph*risonanza2=new TGraph(); 
	t=0;
	ts=10*1/oscf->getAlpha();//tempo oltre al quale l'attrito puo' essere trascurato
	for(int i=0;i<N;i++){

		x2.setComponent(0,0.); //si ristabiliscono le condizioni iniziali
		x2.setComponent(1,0.);
		do{
			x2=myRungeKutta.Passo(t,x2,h,oscf);
			t=t+h;
		}
		while(t<=ts);	//si continua fino a quando l'attrito puo' essere ignorato
		max=x2.getComponent(0);	//si pone temporanemente il massimo come la posizione all'istante t
		t=t-h;//ritorniamo all'istante t
		//continuiamo a integrare per un tempo di 20s oltre ts	
		do{
			x2=myRungeKutta.Passo(t,x2,h,oscf);
			t=t+h;
			
			if(fabs(x2.getComponent(0))>max) //aggiorniamo la posizione massima trovata
			{
				max=fabs(x2.getComponent(0));
				
			}
		}while(t<=ts+20);
	
		amp=max*2;//il massimo trovato e' la meta' dell'ampiezza
		risonanza2->SetPoint(i,win,amp);
		win+=step;//si aggiorna w della la forzante 
		oscf->setW(win);//si aggiorna w nell'equazione del moto
		t=0;
	}

	//Calcolo della curva di risonanza con Eulero:si esegue lo stesso procedimento	

	max=0;
	win=oscf->getW0()-1;
	oscf->setW(win); 
	TGraph*risonanza1=new TGraph(); 
	t=0;
	for(int i=0;i<N;i++){

		x1.setComponent(0,0.); //si ristabiliscono le condizioni iniziali
		x1.setComponent(1,0.);
		do{
			x1=myEulero.Passo(t,x1,h,oscf);
			t=t+h;
		}
		while(t<=ts);	//si continua fino a quando l'attrito puo' essere ignorato
		max=x1.getComponent(0);	//si pone temporanemente il massimo come la posizione all'istante t
		t=t-h;//ritorniamo all'istante t
		//continuiamo a integrare per un tempo di 20s oltre ts	
		do{
			x1=myEulero.Passo(t,x1,h,oscf);
			t=t+h;
			
			if(fabs(x1.getComponent(0))>max) //aggiorniamo la posizione massima trovata
			{
				max=fabs(x1.getComponent(0));
				
			}
		}while(t<=ts+20);
	
		amp=max*2;//il massimo trovato e' la meta' dell'ampiezza
		risonanza1->SetPoint(i,win,amp);
		win+=step;//si aggiorna la forzante 
		oscf->setW(win);//si aggiorna la forzante anche nel moto
		t=0;
	}

		
		
	//Si fa il grafico di tutto su una sola canvas
	TCanvas*myCanvas=new TCanvas("c1", "c1", 1200,600);
	myCanvas->Divide(3,2);
	myCanvas->cd(1);
	posizione1->GetXaxis()->SetTitle("t [s]");
	posizione1->GetYaxis()->SetTitle("x [m]");	
	posizione1->SetTitle("X(t) oscillatore smorzato-forzato Eulero");				
	posizione1->Draw("AL");//linea continua
	myCanvas->cd(2);
	fasi1->GetXaxis()->SetTitle("x [m]");
	fasi1->GetYaxis()->SetTitle("v [m/s]");	
	fasi1->SetTitle("Spazio delle fasi Eulero");				
	fasi1->Draw("AL");
	myCanvas->cd(3);
	risonanza1->GetXaxis()->SetTitle("w [rad/s]");
	risonanza1->GetYaxis()->SetTitle("Ampiezza [m]");	
	risonanza1->SetTitle("Risonanza Eulero");			
	risonanza1->Draw("A*");
	myCanvas->cd(4);
	posizione2->GetXaxis()->SetTitle("t [s]");
	posizione2->GetYaxis()->SetTitle("x [m]");	
	posizione2->SetTitle("X(t) oscillatore smorzato-forzato Runge-Kutta");
	posizione2->Draw("AL");
	myCanvas->cd(5);
	fasi2->GetXaxis()->SetTitle("x [m]");
	fasi2->GetYaxis()->SetTitle("v [m/s]");	
	fasi2->SetTitle("Spazio delle fasi Runge-Kutta");				
	fasi2->Draw("AL");
	myCanvas->cd(6);
	risonanza2->GetXaxis()->SetTitle("w [rad/s]");
	risonanza2->GetYaxis()->SetTitle("Ampiezza [m]");	
	risonanza2->SetTitle("Risonanza Runge-Kutta");			
	risonanza2->Draw("A*");
	
	myApp.Run(); 
	return 0;
}

