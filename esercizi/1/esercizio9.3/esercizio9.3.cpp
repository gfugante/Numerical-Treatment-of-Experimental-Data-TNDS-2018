/*Verificare l'andamento del rapporto Sn/Rn dove Sn è il volume di una sfera n-dimensionale di raggio 1 e Rn è il volume del "cubo" n-dimensionale ad essa circoscritto (N.B. Rn ha lato 2).
Si usi l'integrazione Monte Carlo, con la funzione integranda costituita da una funzione caratteristica, pari a 1 all'interno della sfera, e pari a 0 nei restanti punti del "cubo".
Per la dimensione 3, se ne valuti la precisione al variare del numero di punti, effettuanto il calcolo con 10000, 40000, 90000 e 160000 punti. Per ognuno di questi valori, ripetere il calcolo 100 volte e fornire la media e la deviazione standard dei valori ottenuti e della media (si dovrebbe ottenere che la deviazione standard è inversamente proporzionale alla radice quadrata del numero di punti).
Si chiede poi di calcolarne il valore per dimensione n da 2 a 5. Si confronti il risultato con il valore esatto del volume di una sfera n-dimensionale è dato da πn/2/Γ(n*0.5+1) dove Γ è la funzione gamma.*/

#include "integrator.h"
#include "F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TPad.h"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	if ( argc != 1 ) {
		cerr << "Usage: " << argv[0] << endl;
		return -1;
	}

	unsigned int n;

	TApplication myApp("app", &argc, argv);

	funzioneBase* myF = new F();

	TCanvas* c1 = new TCanvas("c1", "ESERCIZIO9.3. Integrazione Montecarlo multidimensionale",800,600);
	c1 -> Divide(2,2);

	double Rn, Sn;

 	// PARTE 1

	n = 3;

	cout << endl << "PARTE 1)\nPer n=" << n << " si calcola 100 volte il rapporto Sn/Rn, quindi si estraggono media (Mean), deviazione standard (DevStd) e deviazione standard della media (DevStdMean). Si effettua il calcolo per un numero di punti (Npoints) pari a 10000, 40000, 90000 e 160000." << endl;

	integral* I   = new integral(myF,-1,1,n);

	double sumSnRn;  // Somme
	double sumSnRn2; // Somme dei quadrati
	unsigned int Npoints;
	Rn = pow(2.,n);

	cout << setprecision(4) << fixed << endl;
	
	cout << setw(1) <<  "|"  << setw(8)  << "Npoints" 
		 << setw(3) << " | " << setw(10) << "Mean"
		 << setw(3) << " | " << setw(10) << "DevStd"
		 << setw(3) << " | " << setw(10) << "DevStdMean"
		 << setw(2) << " |"  << endl;
	
	

	// ********* N = 10000 *********

	Npoints = 10000;
	c1 -> cd(1);
	TPad* pad1  = new TPad("pad1","pad1",0,0,1,1,0,0.2,10);
	pad1 -> Draw();
	pad1 -> cd();
	TH1F* hist1 = new TH1F("hist1","Distribuzione S_{3}/R_{3} con N_{points}=10000", 40, 0.5, 0.55 );
	sumSnRn  = 0.;
	sumSnRn2 = 0.;
	
	double Mean1, DevStd1, DevStdMean1;
	for (int i=0; i<100; i++) {
		Sn = I->HitOrMiss(Npoints);
		hist1 -> Fill(Sn/Rn);
		sumSnRn  += Sn/Rn;
		sumSnRn2 += (Sn/Rn)*(Sn/Rn);
	}

	Mean1       = sumSnRn / 100;
	DevStd1     = sqrt( sumSnRn2/100 - Mean1*Mean1 );
	DevStdMean1 = DevStd1/sqrt(100);
	cout << setw(1) <<  "|"  << setw(8)  << Npoints 
		 << setw(3) << " | " << setw(10) << Mean1
		 << setw(3) << " | " << setw(10) << DevStd1
		 << setw(3) << " | " << setw(10) << DevStdMean1
		 << setw(2) << " |"  << endl;
	hist1 -> GetXaxis() -> SetTitle("S_{3}/R_{3}");
	hist1 -> Draw();

	// ********* N = 40000 *********

	Npoints = 40000;
	c1 -> cd(2);
	TPad* pad2  = new TPad("pad2","pad2",0,0,1,1,0,0.2,10);
	pad2 -> Draw();
	pad2 -> cd();
	TH1F* hist2 = new TH1F("hist2","Distribuzione S_{3}/R_{3} con N_{points}=40000", 40, 0.5, 0.55 );
	sumSnRn  = 0.;
	sumSnRn2 = 0.;
	double Mean2, DevStd2, DevStdMean2;
	for (int i=0; i<100; i++) {
		Sn = I->HitOrMiss(Npoints);
		hist2 -> Fill(Sn/Rn);
		sumSnRn  += Sn/Rn;
		sumSnRn2 += (Sn/Rn)*(Sn/Rn);
	}
	Mean2       = sumSnRn / 100;
	DevStd2     = sqrt( sumSnRn2/100 - Mean2*Mean2 );
	DevStdMean2 = DevStd2/sqrt(100);
	cout << setw(1) <<  "|"  << setw(8)  << Npoints 
		 << setw(3) << " | " << setw(10) << Mean2
		 << setw(3) << " | " << setw(10) << DevStd2
		 << setw(3) << " | " << setw(10) << DevStdMean2
		 << setw(2) << " |"  << endl;
	hist2 -> GetXaxis() -> SetTitle("S_{3}/R_{3}");
	hist2 -> Draw();

	// ********* N = 90000 *********

	Npoints = 90000;
	c1 -> cd(3);
	TPad* pad3  = new TPad("pad3","pad3",0,0,1,1,0,0.2,10);
	pad3 -> Draw();
	pad3 -> cd();
	TH1F* hist3 = new TH1F("hist3","Distribuzione S_{3}/R_{3} con N_{points}=90000", 40, 0.5, 0.55 );
	sumSnRn  = 0.;
	sumSnRn2 = 0.;
	double Mean3, DevStd3, DevStdMean3;
	for (int i=0; i<100; i++) {
		Sn = I->HitOrMiss(Npoints);
		hist3 -> Fill(Sn/Rn);
		sumSnRn  += Sn/Rn;
		sumSnRn2 += (Sn/Rn)*(Sn/Rn);
	}
	Mean3       = sumSnRn / 100;
	DevStd3     = sqrt( sumSnRn2/100 - Mean3*Mean3 );
	DevStdMean3 = DevStd3/sqrt(100);
	cout << setw(1) <<  "|"  << setw(8)  << Npoints 
		 << setw(3) << " | " << setw(10) << Mean3
		 << setw(3) << " | " << setw(10) << DevStd3
		 << setw(3) << " | " << setw(10) << DevStdMean3
		 << setw(2) << " |"  << endl;
	hist3 -> GetXaxis() -> SetTitle("S_{3}/R_{3}");
	hist3 -> Draw();

	// ********* N = 160000 *********

	Npoints = 160000;
	c1 -> cd(4);
	TPad* pad4  = new TPad("pad4","pad4",0,0,1,1,0,0.2,10);
	pad4 -> Draw();
	pad4 -> cd();
	TH1F* hist4 = new TH1F("hist4","Distribuzione S_{3}/R_{3} con N_{points}=160000", 40, 0.5, 0.55 );
	sumSnRn  = 0.;
	sumSnRn2 = 0.;
	double Mean4, DevStd4, DevStdMean4;
	for (int i=0; i<100; i++) {
		Sn = I->HitOrMiss(Npoints);
		hist4 -> Fill(Sn/Rn);
		sumSnRn  += Sn/Rn;
		sumSnRn2 += (Sn/Rn)*(Sn/Rn);
	}
	Mean4       = sumSnRn / 100;
	DevStd4     = sqrt( sumSnRn2/100 - Mean4*Mean4 );
	DevStdMean4 = DevStd4/sqrt(100);
	cout << setw(1) <<  "|"  << setw(8)  << Npoints 
		 << setw(3) << " | " << setw(10) << Mean4
		 << setw(3) << " | " << setw(10) << DevStd4
		 << setw(3) << " | " << setw(10) << DevStdMean4
		 << setw(2) << " |"  << endl;
	hist4 -> GetXaxis() -> SetTitle("S_{3}/R_{3}");
	hist4 -> Draw();
		
	

	cout << setprecision(2) << fixed << endl;
	cout << "La deviazione standard delle misure dovrebbe dipendere da Npoints tramite la relazione DevStd=k*Npoints^alpha, con k costante di proporzionalità e alpha_atteso=-0.50\nPer verificarne l'andamento si calcola alpha considerando due coppie di valori:" << endl;

	cout << "alpha1-3 = " << log(DevStd1/DevStd3)
							/log(1.*10000/90000) << endl;
	cout << "alpha1-4 = " << log(DevStd1/DevStd4)
							/log(1.*10000/160000) << endl;
	cout << "Si osserva che lo scostamento dal valore atteso e' circa del 4%." << endl;	

 	// PARTE 2

	cout << endl << "PARTE 2)\nSi calcola Sn/Rn per n=2,..,5 e si confronta con il valore atteso (Sn/Rn Exp)." << endl;

	cout << setprecision(4) << fixed << endl;

	
	cout << setw(2) <<  "| " << setw(3)  << "n " 
		 << setw(3) << " | " << setw(10) << "Sn/Rn"
		 << setw(3) << " | " << setw(10) << "Sn/Rn Exp"
		 << setw(2) << " |"  << endl;
	

	n = 2;
	Rn = pow(2.,n);
	I   = new integral(myF,-1,1,n);
	Sn = I->HitOrMiss(160000);
	cout << setw(2) <<  "| " << setw(3)  << n
	     << setw(3) << " | " << setw(10) << Sn/Rn
         << setw(3) << " | " << setw(10) << VolumeIpersfera(n,1.)/Rn
         << setw(2) << " |"  << endl;

	n = 3;
	Rn = pow(2.,n);
	I   = new integral(myF,-1,1,n);
	Sn = I->HitOrMiss(160000);
	cout << setw(2) <<  "| " << setw(3)  << n
	     << setw(3) << " | " << setw(10) << Sn/Rn
         << setw(3) << " | " << setw(10) << VolumeIpersfera(n,1.)/Rn
         << setw(2) << " |"  << endl;

	n = 4;
	Rn = pow(2.,n);
	I   = new integral(myF,-1,1,n);
	Sn = I->HitOrMiss(160000);
	cout << setw(2) <<  "| " << setw(3)  << n
	     << setw(3) << " | " << setw(10) << Sn/Rn
         << setw(3) << " | " << setw(10) << VolumeIpersfera(n,1.)/Rn
         << setw(2) << " |"  << endl;

	n = 5;
	Rn = pow(2.,n);
	I   = new integral(myF,-1,1,n);
	Sn = I->HitOrMiss(160000);
	cout << setw(2) <<  "| " << setw(3)  << n
	     << setw(3) << " | " << setw(10) << Sn/Rn
         << setw(3) << " | " << setw(10) << VolumeIpersfera(n,1.)/Rn
         << setw(2) << " |"  << endl;

	

	cout << "Si osserva che lo scostamento dal valore atteso e' inferiore allo 0.4%" << endl;

	myApp.Run();

	return 0;
}
