#include <iostream>

#include "TH1F.h" //disegna istogrammi monodimensionali
#include "TApplication.h" //per gestire più interfacce e tenerle aperte?
#include "TCanvas.h" //per aprire l'interfaccia

#include "Random.h"
#include "FunzioneBase.h"


using namespace std;

int main(int argc, char** argv)
{

	
    TApplication app("app", &argc, argv); //creo un oggetto TApplication
	Gaussiana *g1 = new Gaussiana(1.,1.);
	Gaussiana *g2 = new Gaussiana(0.,2.);
	Random rand(3); //creo un oggetto Random

	double a = -5;
	double b = 5;
	TH1F h1("nome", "Gaussiana 1", 100, a,b); //creo un oggetto TH1F
	TH1F h2("nome2", "Gaussiana 2", 100, a,b); //creo un oggetto TH1F

    for (int i = 0; i < 1E5; i++)
        {
            double n1 = rand.AccRej(a,b,g1);
            double n2 = rand.AccRej(a,b,g2);            
            h1.Fill(n1);
            h2.Fill(n2);
        }
    
    TCanvas *c1 = new TCanvas("c1","c1");
    TCanvas *c2 = new TCanvas("c2","c2");
    c1 -> cd();
    h1.Draw();
    c2 -> cd();
    h2.Draw();
    
    app.Run();
    
    return 0;
}
