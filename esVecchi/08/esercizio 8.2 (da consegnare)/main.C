#include <iostream>

#include "TH1F.h" 
#include "TApplication.h" 
#include "TCanvas.h" 
#include "TFile.h"
#include "Random.h"


using namespace std;

int main(int argc, char** argv)
{

	
  TApplication app("app", &argc, argv);
	Random rand(3);

	double a = -5;
	double b = 5;
	TH1F h1("nome", "Gaussiana", 100, a,b); 
	TFile f("histos.root","new");

    for (int i = 0; i < 1E5; i++)
        {
            double n1 = rand.Gauss(0,1);            
            h1.Fill(n1);
        }
    
    TCanvas *c1 = new TCanvas("c1","c1");
    c1 -> cd();
    h1.Write();
    h1.Draw();
    
    app.Run();
    
    return 0;
}
