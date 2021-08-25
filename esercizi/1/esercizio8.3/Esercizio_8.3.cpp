/*Si genera una serie di numeri casuali uniformemente distribuiti in [0,1] e si la somma eseguita su un numero n di elementi consecutivi della serie generata.Si calcola la varianza della serie di numeri generata e della serie delle somme. Si passa da riga di comando sia il numero di elementi della serie di partenza (10000 può essere un
buon numero) ed il numero di elementi su cui fare la somma. Si creano due istogrammi che contengono la distribuzione dei numeri generata e la distribuzione delle somme.
Per verificare che la varianza delle somme scala con il numero di numeri casuali lanciare a mano il programma variando soltanto il numero degli elementi su cui si vuole sommare. Sono stati salvati quasti valori nel file VerificaTLC.dat e poi si è disegnato il grafico con il programma disegna_ROOT.cpp. per vericarne il funzionamento*/



#include<iomanip>
#include "random.h"
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#define nvolte 5

using namespace std;

int main(int argc, char**argv){
	if(argc!=3){
		cerr<<"Usage:"<<argv[0]<<" <numerodivalori> <numerosucuisommare> "<<endl;
		return -1; 
	}
	int nn, ns, k=1, j=0;
	double sum=0.,media=0.,var=0.;
	ofstream outfile;
	outfile.open("VerificaTLC.dat",ofstream::app);

	nn=atoi(argv[1]);//numero di elementi considerati
	ns=atoi(argv[2]);//numero di elementi su cui si somma
	TApplication app("app", &argc, argv);
	int nvero=nn-nn%ns; //escludo gli utlimi valori tali per cui non riesco a fare una somma di ns elementi 
	double*v=new double[nn]; //vettore con tutti i numeri generati
	int nns= static_cast<int>(nn/ns);//numero delle somme fatte
	double*w=new double[nns]; //vettore delle somme
	
	Random rand(3);
	TH1F *h=new TH1F ("nome", "Teorema limite centrale: somme", 100,0.,ns);
	TH1F *h2=new TH1F ("nome2", "Teorema limite centrale: numeri", 100,0.,1);

	//Si generano nn numeri casuali, si riempie un istogramma e li si salva in un vettore. Calcoliamo poi le somme su ns numeri consecutivi, si riempie l'istogramma e li si salva in un vettore. I numeri su cui si effettua l'operazione di somma sono nvero.
	cout<<endl;
	cout<<"Numero di numeri casuali su cui si somma: "<<ns<<endl;
	cout<<"Numero di numeri casuali effettivamente coivolti nell'operazione di somma: "<<nvero<<endl;
	cout<<"Numero delle somme effettuate:"<<nns<<endl;			
	cout<<"Nell'istogramma relativo ai numeri casuali sono stati immessi solo quelli effettivamente utilizzati per effettuare le somme."<<nns<<endl;		
	cout<<endl;

	for (int i=0; i<nns; i++){ 
		do{
		double n=rand.Rand();
		v[j]=n; 
		h2->Fill(n);
		sum+=n; 
		j++;} while (j<k*ns);
		w[i]=sum;
		h->Fill(sum);		
		k++;
		sum=0;
		}

	for(int i=0;i<nvero;i++){
		media+= v[i];}
	media=media/nvero;
	cout<<setprecision(4);
	cout<<"La media dei numeri: "<<media<<endl;
	for(int i=0;i<nvero;i++)
		var+= pow((v[i]-media),2);
	var= var/(nvero-1);
	cout<<setprecision(3);
	cout<<"La varianza dei numeri: "<<var<<endl;

	media=0.;
	var=0.;
	for(int i=0;i<nns;i++){
		media+= w[i];}
	media=media/nns;
	cout<<setprecision(4);
	cout<<"La media delle somme: "<<media<<endl;
	for(int i=0;i<nns;i++)
		var+= pow((w[i]-media),2);
	var= var/(nns-1);
	cout<<setprecision(3);
	cout<<"La varianza delle somme: "<<var<<endl;
	//outfile<<"Ns"<<"\t"<<"Varianza"<<endl;
	outfile<<ns<<"\t"<<var<<endl;
	TCanvas*c1=new TCanvas("c1", "c1");
	c1->cd();
	h->Draw();
	h->GetXaxis()->SetTitle("Valore numerico");
	h->GetYaxis()->SetTitle("Frequenza");	
	TCanvas*c2=new TCanvas("c2", "c2");
	c2->cd();
	h2->Draw();
	h2->GetXaxis()->SetTitle("Valore numerico");
	h2->GetYaxis()->SetTitle("Frequenza");	



	outfile.close();	
	outfile.clear();
	delete [] v;
	delete [] w;
	app.Run(); 
	return 0;
}
	
