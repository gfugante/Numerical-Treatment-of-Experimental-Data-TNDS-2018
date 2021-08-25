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
	funzioneVettorialeBase *Osc=new oscillatoreArmonico(1.);
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
	for(int i=0; i<nsteps; i++){
		E->SetPoint(i,t,x.getComponent(0));
		R->SetPoint(i,t,y.getComponent(0));
		x=myEuler.Passo(t,x,h,Osc);
		y=myRunge.Passo(t,y,h,Osc);
		t=t+h;
	}
	TCanvas *myCanvas=new TCanvas("3","");
	myCanvas->Divide(1,2);
	myCanvas->cd(1);
	E->GetXaxis()->SetTitle("Metodo Eulero, t[s]");
	E->GetYaxis()->SetTitle("x [m]");
	E->Draw("AL");
	myCanvas->cd(2);
	R->GetXaxis()->SetTitle("Metodo RungeKutta, t[s]");
	R->GetYaxis()->SetTitle("x [m]");
	R->Draw("AL");
	app.Run();
	return 0;
}
