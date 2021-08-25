#include <iostream>
#include "vettorelineare.h"
#include "vettore.h"
#include "equazionidifferenziali.h"
#include "math.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;
int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
  	cout<<"Inserisci il passo di integrazione: "<<endl;
  	double h;
  	cin>>h;
	Eulero myEuler;
  	RungeKutta myRunge;
	funzioneVettorialeBase *Forz=new oscillatoreforzato(10,10,1/30.);
	double tmax=30.;
	int nsteps=int(tmax/h+0.5);
	double t=0;
	vettoreLineare x(2);
	x.setComponent(0,0.);
	x.setComponent(1,1.);
	vettoreLineare y(2);
	y.setComponent(0,0.);
	y.setComponent(1,1.);
	TGraph* E=new TGraph();
	TGraph* R=new TGraph();
	TGraph* P=new TGraph();
	for(int i=0; i<nsteps; i++){
		E->SetPoint(i,t,x.getComponent(0));
		R->SetPoint(i,t,y.getComponent(0));
		x=myEuler.Passo(t,x,h,Forz);
		y=myRunge.Passo(t,y,h,Forz);
		t=t+h;
	}
	double v,a;
	for(int i=0; i<21; i++){
		funzioneVettorialeBase *F=new oscillatoreforzato(10,9+0.1*i,1/30.);
		t=0;
		h=0.1;
		y.setComponent(0,0);
		y.setComponent(1, 0.);
		while(t<50){
			y=myRunge.Passo(t,y,h,F);
			t=t+h;
		}
		if(y.getComponent(1)<0){
			while(y.getComponent(1)<=0){
				a=y.getComponent(0);
				v=y.getComponent(1);
				y=myRunge.Passo(t,y,h,Forz);
				t=t+h;
			}
		}
		else{
			while(y.getComponent(1)>=0){
				a=y.getComponent(0);
				v=y.getComponent(1);
				y=myRunge.Passo(t,y,h,Forz);
				t=t+h;
			}
		}
		P->SetPoint(i,9+0.1*i,fabs(a));
	}
	TCanvas *myCanvas=new TCanvas("3","");
	myCanvas->Divide(3,2);
	myCanvas->cd(1);
	E->GetXaxis()->SetTitle("Metodo Eulero, t [s]");
	E->GetYaxis()->SetTitle("x[m]");
	E->Draw("AL");
	myCanvas->cd(2);
	R->GetXaxis()->SetTitle("Metodo RungeKutta, t [s]");
	R->GetYaxis()->SetTitle("x[m]");
	R->Draw("AL");
	myCanvas->cd(3);
	P->GetXaxis()->SetTitle("Metodo RungeKutta, pulsazione [rad/s]");
	P->GetYaxis()->SetTitle("Ampiezza");
	P->Draw("APL*");
	app.Run();
	return 0;
}
