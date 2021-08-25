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
	funzioneVettorialeBase *Pend=new pendolo(1.);
	double tmax=70;
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
		x=myEuler.Passo(t,x,h,Pend);
		y=myRunge.Passo(t,y,h,Pend);
		t=t+h;
	}
	double v;
	for(int i=1; i<30; i++){
		double A=0.1*i;
		t=0;
		h=0.1;
		y.setComponent(0,-A);
		y.setComponent(1, 0.);
		while(y.getComponent(1)>=0){
				v=y.getComponent(1);
				y=myRunge.Passo(t,y,h,Pend);
				t=t+h;
		}
		double T=t-(h*y.getComponent(1)/(y.getComponent(1)-v));
		T=T*2;
		P->SetPoint(i,A,T);
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
	P->GetXaxis()->SetTitle("Metodo RungeKutta, Periodo [s]");
	P->GetYaxis()->SetTitle("Ampiezza [rad]");
	P->Draw("AP*");
	app.Run();
	return 0;
}
