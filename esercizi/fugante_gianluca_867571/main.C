#include <iostream>
#include <cmath>

#include "Integratore.h"
#include "FunzioneIntegrale.h"
/*
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
*/


using namespace std;

int main(int argc, char** argv)
{
/*	TApplication app("app", &argc, argv);
	TCanvas *MyCanvas = new TCanvas("MyCanvas", "MyCanvas");
	TGraph *Ampiezza = new TGraph();
*/
	
	ATheta* A = new ATheta();
	A->SetLambda(500*1E-9);					//metri!
	A->SetR(50*1E-6);

	Integral* integrale = new Integral(0.,A->GetR(),A);

	
	double T,I;
	
	for(unsigned int i=0; i<=100; i++)
	{
		
		T = -0.1 + (2*i*1E-3);
		A->SetTheta(T);
		I = 1E6*integrale->Trapezoide(1E-4);
		cout<<I/500000<<endl;
//		Ampiezza->SetPoint(i, T, I);
		
	}
	
/*	
	MyCanvas->cd();
	Ampiezza->SetTitle("A (Theta)");
	Ampiezza->GetXaxis()->SetTitle("Theta [rad]");
	Ampiezza->GetYaxis()->SetTitle("Ampiazza della figura di diffrazione [micron]");
	Ampiezza->Draw("AL*");
	
	app.Run();
*/	
	

	return 0;
}
