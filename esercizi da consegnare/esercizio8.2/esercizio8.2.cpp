#include <iostream>

#include "TH1F.h" //disegna istogrammi monodimensionali
#include "TApplication.h" //per gestire più interfacce e tenerle aperte?
#include "TCanvas.h" //per aprire l'interfaccia

#include "Random.h"
#include "FunzioneBase.h"
#include "Gaussiana.h"


using namespace std;

int main(int argc, char** argv)
{	
    TApplication app("app", &argc, argv); //creo un oggetto TApplication

	Random rand(3); //creo un oggetto Random

	double a = -5.;
	double b = 5.;

	TH1F h1("nome", "Box Muller", 100, a ,b); //creo un oggetto TH1F
	TH1F h2("nome2", "Esponenziale", 100, 0. , 50.); //creo un oggetto TH1F

    for (int i = 0; i < 1E5; i++)
        {
            double n1 = rand.BoxMuller(0.,1.);
			double n2 = rand.Exponential(0.1);

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
