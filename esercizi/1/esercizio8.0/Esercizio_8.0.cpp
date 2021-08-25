/*Questo un programma che utilizza il generatore di numeri casuali implementato e riempie un istogramma con 100000 numeri casuali tra 0 e 1; si è verificato, stampando a video i parametri  che il periodo del generatore con parametri a = 4, c = 1, m = 9 è molto limitato.*/

#include "random.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <iostream>
using namespace std;

int main(int argc, char**argv){
	//Riempiamo l'istogramma con 100000 numeri casuali: si osserva che la distribuzione e' uniforme
	TApplication app("app", &argc, argv);

	Random rand(3);
	TH1F *h=new TH1F ("Numeri casuali", "Istogramma con 100000 numeri casuali", 100,0., 1.);

	for (int i=0; i<100000; i++){
		double n=rand.Rand();
		h->Fill(n);
		}
	
	
	//Verifica della limitatezza del periodo
	cout<<endl;
	cout<<"Per verificare la limitatezza del periodo sono stati stampati di seguito trenta numeri casuali:"<<endl; 	
	rand.setA(4);
	rand.setC(1);
	rand.setM(9);
	for (int i=0; i<30; i++){
		double n=rand.Rand();
		cout<<i+1<<")"<<n<<endl;
		}
	cout<<"Si nota che la stessa sequenza numerica si ripete esattamente uguale dopo nove numeri"<<endl;
	//Disegnamo l'istogramma
	TCanvas*c1=new TCanvas("c1", "c1");
	c1->cd();
	h->Draw();
	h->GetXaxis()->SetTitle("Valore numerico");
	h->GetYaxis()->SetTitle("Frequenza");	

	app.Run(); 
	return 0;
}
	
