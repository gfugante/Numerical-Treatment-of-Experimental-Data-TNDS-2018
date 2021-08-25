#include <iostream>
#include <cstdlib>

#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"

#include "VettoreLineare.h"
#include "RungeKutta.h"
#include "OscForzatoSmorzato.h"

using namespace std;

int main(int argc, char** argv){
	
	if (argc != 3){
		cerr << "Usare: " << argv[0] << " <passo integrazione> <pulsazione della forzante>" <<  endl;
		exit(-1);
	}
	
	TApplication app("app", &argc, argv);		
	TCanvas *MyCanvas = new TCanvas("MyCanvas", "MyCanvas");
	TGraph *Posizione = new TGraph();
	TGraph *Risonanza = new TGraph();
	
	VettoreLineare x(2);
	x.SetComponent(0, 0.);
	x.SetComponent(1, 0.);

	double h = atof(argv[1]);	
	double omegaf = atof(argv[2]);
	double omega0 = 10;
	double alfa   = 1./30.;
	double t      = 0.;
	double A      = 0.;
	
	unsigned int nPoint = 0;
	
	OscForzatoSmorzato *OFS = new OscForzatoSmorzato(omega0, omegaf, alfa);

	RungeKutta myRK;
	
	cout << "Calcolo equazione differenziale, attendere prego..." << endl;
	
	while (t < 1. / alfa)
	{
		x = myRK.Passo(t, x, h, OFS);
		Posizione->SetPoint(nPoint, t, x.GetComponent(0));
		t += h;
		nPoint++;
	}
	
	cout << "Calcolo equazione differenziale terminato." << endl;
	cout << "Tracciamento della curva di risonanza, attendere prego..." << endl;
	
	nPoint = 0;
	omegaf = 9;
	while (omegaf < 11)
	{
		OscForzatoSmorzato *OFS1 = new OscForzatoSmorzato(omega0, omegaf, alfa);
		x.SetComponent(0, 0.);
		x.SetComponent(1, 0.);
		A = 0;
		t = 0;
		while (t<10/alfa)
		{
			x = myRK.Passo(t, x, h, OFS1);
			if (t > 9 / alfa)
				A = max( A, abs(x.GetComponent(0) ) );
			t += h;
		}
		Risonanza->SetPoint(nPoint, omegaf, A);
		
		omegaf += 0.02;
		nPoint++;
	}
	cout << "Tracciamento della curva di risonanza terminato." << endl;
	MyCanvas->Divide(1,2);
	
	MyCanvas->cd(1);
	Posizione->SetTitle("Oscillatore armonico forzato smorzato");
	Posizione->GetXaxis()->SetTitle("tempo [s]");
	Posizione->GetYaxis()->SetTitle("Posizione [m]");
	Posizione->Draw("AL");
	
	MyCanvas->cd(2);
	Risonanza->SetTitle("Curva di risonanza");
	Risonanza->GetXaxis()->SetTitle("pulsazione forzante [rad/s]");
	Risonanza->GetYaxis()->SetTitle("Ampiezza oscillazione [m]");
	Risonanza->SetMarkerStyle(20);
	Risonanza->SetMarkerSize(0.4);
	Risonanza->Draw("ALP");
	
	app.Run();
	
	return 0;
}

