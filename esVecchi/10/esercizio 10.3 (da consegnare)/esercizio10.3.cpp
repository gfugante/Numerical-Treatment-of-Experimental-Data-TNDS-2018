#include <iostream> 
#include <cmath> 
#include <cstdlib>

#include "TApplication.h"
#include "TGraph.h" 
#include "TCanvas.h" 
#include "TAxis.h"

#include "EquazioniDifferenziali.h" 
#include "VettoreLineare.h" 
#include "Vettore.h" 


using namespace std; 

const double g = 9.806;

int main(int argc, char** argv){ 								
	TApplication myApp("myApp", 0, 0); 

	if(argc != 2){ 
		cerr << "Usage: " << argv[0] << " <passo di integrazione>" << endl; 
		exit (-1); 
	} 


	double h = atof(argv[1]); 
	RungeKutta myRK; 
	Pendolo *pendolo = new Pendolo(); 
	TGraph *periodo = new TGraph(); 

	double A = M_PI / 50.; 
	double v;
	double T;

	unsigned int counter = 0;
	 
	VettoreLineare x(2); 

	
	for(A=h; A <= M_PI; A += M_PI/50.)
	{
		double t = 0.;
		x.setComponent(0, -A); 
		x.setComponent(1, 0.);

		counter++;
	
		while(x.getComponent(1) >= 0.)
		{
			v = x.getComponent(1);
			x = myRK.passo(t, x, h, pendolo);
			t += h;
		}
	
		T =  t -  x.getComponent(1) * h / (x.getComponent(1) - v);
		T = 2. * T;
		
		periodo->SetPoint(counter, abs(x.getComponent(0)), T );
	} 


	TCanvas *myCanvas = new TCanvas(); 
	 
	myCanvas->cd(); 
	periodo->Draw("AL*"); 
	periodo->GetXaxis()->SetTitle("Ampiezza[rad]"); 
	periodo->GetYaxis()->SetTitle("Periodo[s]"); 
	 
	myApp.Run(); 

	delete periodo; 
	delete pendolo; 

	return 0; 
}
