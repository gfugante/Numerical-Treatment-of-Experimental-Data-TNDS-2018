#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include "TH1F.h" 
#include "TApplication.h"
#include "TCanvas.h"

#include "Random.h"
#include "Vettore.h"


using namespace std;

int main(int argc, char **argv)
{
	TApplication app("app", &argc, argv);

	if (argc != 3)
	{
		cerr << "Stai usando: <esercizio8.3> <N numeri da generare> <M numeri da sommare>" << endl;
		return -1;
	}

	unsigned int n = atoi(argv[1]);
	unsigned int m = atoi(argv[2]);
	double k = n/m;

	
	Random rand(12);
	Vettore *list = new Vettore(n);
	Vettore *somma = new Vettore(k);

	TH1F h1("numeri generati", "distribuzione", n, 0, 1); //creo un oggetto TH1F
	TH1F h2("somme", "distribuzione somme", m, 0, m);

	for(unsigned int i = 0; i < n; i++)
	{
		double x = rand.Uniform(0.,1.);
		list->SetComponent(i, x);
		h1.Fill(x);
	}

	
	for(unsigned int j = 0; j < k; j++)
	{
		double sum = 0.;
		for(unsigned int i = j*m; i < (j+1)*m; i++)
		{
			sum += list->GetComponent(i);
		}
		somma->SetComponent(j, sum);
		h2.Fill(somma->GetComponent(j));
	}

	//list
	double medialist = list->Media();
	double varianzalist = list->Varianza();

	cout<<"La serie di numeri generata ha media "<<scientific<<setprecision(3)<<medialist<<" e varianza "<<varianzalist<<"."<<endl;

	//somma
	double mediasomma = somma->Media();
	double varianzasomma = somma->Varianza();


	cout<<"La serie di numeri generata ha media "<<scientific<<setprecision(3)<<mediasomma<<" e varianza "<<varianzasomma<<"."<<endl;

	
	
	TCanvas *c1 = new TCanvas("c1","c1");
	TCanvas *c2 = new TCanvas("c2","c2");

	c1->cd();
	h1.Draw();

	c2->cd();
	h2.Draw();

	list->~Vettore();
	somma->~Vettore();

	app.Run();
    
    return 0;
}
