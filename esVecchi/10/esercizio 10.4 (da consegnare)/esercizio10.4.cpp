#include <iostream> 
#include <cmath> 
#include <cstdlib>

#include "EquazioniDifferenziali.h" 
#include "VettoreLineare.h" 
#include "Vettore.h" 

#include "TApplication.h"
#include "TGraph.h" 
#include "TCanvas.h" 
#include "TAxis.h" 


using namespace std; 

int main(int argc, char** argv){ 

	TApplication myApp("myApp", 0, 0);
	if(argc != 2){ 
		cerr<<"Usage: "<< argv[0] << " <passo di integrazione>" << endl; 
		exit (-1); 
	} 

	double h = atof(argv[1]); 
 
	RungeKutta rk; 
	oscillatoreForzatoSmorzato *osc = new oscillatoreForzatoSmorzato(); 
	osc->setOmega0(10.);
	osc->setAlpha(1./30.);


	TGraph *omega1 = new TGraph(); 
	TGraph *omega2 = new TGraph();
	TGraph *omega3 = new TGraph();
	TGraph *omega4 = new TGraph();
	TGraph *omega5 = new TGraph();
	TGraph *omega6 = new TGraph();
	TGraph *omega7 = new TGraph();
	TGraph *omega8 = new TGraph();
	TGraph *omega9 = new TGraph();
	TGraph *omega10 = new TGraph();
	
	TGraph* risonanza = new TGraph();
	TGraph* omega [] = {omega1,omega2,omega3,omega4,omega5,omega6,omega7,omega8,omega9,omega10};
	for(unsigned int i=0; i<10; i++) omega[i] = new TGraph();

	double tmax = 12./osc->getAlpha(); 
	int nstep = int (tmax / h + 0.5 ); 
	double t = 0.;
	 
	VettoreLineare x(2); 
	x.setComponent(0,0.); 
	x.setComponent(1,0.); 

	int n;
	double v1,v2;
	double* tmp = new double[10];

	double* forzante = new double[10];
		for(unsigned int i=0; i<10; i++) forzante[i] = 2*i;

	double a = 0.;


	for(unsigned int i=0; i<10; i++){
		osc->setOmegaf(forzante[i]);

		for(int step = 0; step < nstep; step++){ 
			v1=x.getComponent(1);
			omega[i]->SetPoint(step, t, x.getComponent(0) );
			v2=x.getComponent(1);
					 
			if(t>(10./osc->getAlpha()) && v1*v2<0){
				if(n==10)	n=0;
				tmp[n]=x.getComponent(0);
				n++;
			} 

			x = rk.passo(t, x, h, osc); 
			t += h;
		}
		//trovo il massimo delle ampiezze campionate
		for(unsigned int j=0; j<10; j++){ if(tmp[i]>a) a=tmp[i];}  
		risonanza->SetPoint(i,forzante[i],a);
		a = 0.;			 
	}

	TCanvas *c1 = new TCanvas("c1","c1");
	TCanvas *c2 = new TCanvas("c2","c2");
	TCanvas *c3 = new TCanvas("c3","c3");
	TCanvas *c4 = new TCanvas("c4","c4");
	TCanvas *c5 = new TCanvas("c5","c5");
	TCanvas *c6 = new TCanvas("c6","c6");
	TCanvas *c7 = new TCanvas("c7","c7");
	TCanvas *c8 = new TCanvas("c8","c8");
	TCanvas *c9 = new TCanvas("c9","c9");
	TCanvas *c10 = new TCanvas("c10","c10");
	TCanvas *c11 = new TCanvas("c11","c11");

	TCanvas* c[10] = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10};	 

	for(unsigned int i=0; i<10; i++){
		c[i]->cd();
//		omega[i]->SetTitle("Pulsazione forzante: "+forzante[i]+"rad/s");
		omega[i]->Draw("AL"); 
		omega[i]->GetXaxis()->SetTitle("t[s]"); 
		omega[i]->GetYaxis()->SetTitle("x[m]"); 
	}
	
	c11->cd();; 
	risonanza->Draw("AL"); 
	risonanza->GetXaxis()->SetTitle("pulsazione[rad/s]"); 
	risonanza->GetYaxis()->SetTitle("ampiezza[m]"); 
	
	
	myApp.Run(); 

	delete []tmp;
	delete []forzante;  
	delete osc; 
	
	return 0; 
}
