#include <iostream>
#include <cmath>


#include "SferaChar.h"
#include "Integratore.h"

#include "TH1F.h" 
#include "TApplication.h" 
#include "TCanvas.h" 
#include "TAxis.h"


using namespace std;

int main(int argc, char **argv)
{
	TApplication app("app", &argc, argv);

	FunzioneBase *sfera = new SferaChar(1.);
	Integral myInt(-1,1, sfera);
	double Sn;

	TH1F h1("Volume sfera", "10 000 punti", 100, 0.5, 0.54);
	TH1F h2("Volume sfera", "40 000 punti", 100, 0.5, 0.54);
	TH1F h3("Volume sfera", "90 000 punti", 100, 0.5, 0.54);
	TH1F h4("Volume sfera", "160 000 punti", 100, 0.5, 0.54);
	for(unsigned int i = 0; i < 100; i++)
	{
		Sn = myInt.media(10000, 3);
		h1.Fill(Sn / 8.);

		Sn = myInt.media(40000, 3);
		h2.Fill(Sn / 8.);

		Sn = myInt.media(90000, 3);
		h3.Fill(Sn / 8.);

		Sn = myInt.media(1600000, 3);
		h4.Fill(Sn / 8.);
	}

	TCanvas *c1 = new TCanvas("c1","c1");
	TCanvas *c2 = new TCanvas("c2","c2");
	TCanvas *c3 = new TCanvas("c3","c3");
	TCanvas *c4 = new TCanvas("c4","c4");

	c1->cd();
	h1.Draw();

	c2->cd();
	h2.Draw();

	c3->cd();
	h3.Draw();

	c4->cd();
	h4.Draw();

	cout << "Volume dell'ipersfera al variare delle dimensioni:" << endl;	
	cout << "dimensioni	Volume integrale 	Volume esatto" << endl;
	unsigned int dim;
	for(dim = 2; dim <= 5; dim++)
		cout << "    " << dim << "		" << myInt.media(1000000, dim) 
			 << "			" << pow(M_PI, dim/2.) / tgamma( dim * 0.5 + 1.) << endl; 

	app.Run();

	return 0;
}
