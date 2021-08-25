#include <iostream>

#include "TH1F.h" //disegna istogrammi monodimensionali
#include "TApplication.h" //per gestire più interfacce e tenerle aperte?
#include "TCanvas.h" //per aprire l'interfaccia

#include "Random.h"

using namespace std;

int main(int argc, char** argv)
{
    TApplication app("app", &argc, argv); //creo un oggetto TApplication

    Random rand(3); //creo un oggetto Random
    TH1F h("nome", "titolo", 100, 0, 1); //creo un oggetto TH1F

    for (int i = 0; i < 1E5; i++)
        {
            double n = rand.Rand();
            h.Fill(n);
        }
    
    TCanvas *c1 = new TCanvas("c1","c1");
    c1 -> cd();
    h.Draw();

    app.Run();
    
    return 0;
}
