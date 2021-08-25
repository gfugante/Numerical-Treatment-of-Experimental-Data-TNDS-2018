#include <iostream>
#include <cstdlib>

#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"

#include "VettoreLineare.h"
#include "RungeKutta.h"
#include "Pendolo.h"

using namespace std;

int main(int argc, char** argv){
	
	if (argc != 2){
		cerr << "Usare: " << argv[0] << " <lunghezza pendolo[m]>" << endl;
		exit(-1);
	}
	
	TApplication app("app", &argc, argv);		
	TCanvas *MyCanvas = new TCanvas("Canvas", "pendolo");
	TGraph *Periodo = new TGraph();
	
	VettoreLineare x(2);

	double l = atof(argv[1]);	
	double h = 1e-4;
	
	double A = M_PI / 50.;
	double v, T;
	double t = 0.;
	
	unsigned int nPoint = 0;
	
	Pendolo *p = new Pendolo(l);

	RungeKutta myRK;
	
	for (A; A < (M_PI); A += M_PI / 50 )
	{
		x.SetComponent(0, -A);
		x.SetComponent(1, 0.);
		t = 0;

		while (x.GetComponent(1) >= 0.)
		{
			v = x.GetComponent(1);
			x = myRK.Passo(t, x, h, p);
			t +=h;
		}

		T = 2 * ( (t - h) - v * h / (v - x.GetComponent(1) ) );
		Periodo->SetPoint(nPoint, A, T);
		
		nPoint++;
	}
	
	MyCanvas->cd();
	Periodo->SetTitle("Periodo del pendolo");
	Periodo->GetXaxis()->SetTitle("Ampiazza oscillazione [rad]");
	Periodo->GetYaxis()->SetTitle("Periodo [s]");
	Periodo->Draw("AL*");
	
	app.Run();
	
	return 0;
}

