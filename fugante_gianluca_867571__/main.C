#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath>
//#include "TApplication.h"
//#include "TGraph.h"
//#include "TCanvas.h"
//#include "TAxis.h"
#include "VettoreLineare.h"
#include "Vettore.h"
#include "RungeKutta.h"
#include "Calorimetro.h"
#include "Random.h"
#define N 1000
using namespace std;

int main(int argc, char** argv){
	
	
	//TApplication app("app", &argc, argv);
	//TCanvas *MyCanvas = new TCanvas("MyCanvas", "MyCanvas");
	ofstream out("soluzione.txt");
	cout<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<< "I cicli sono piuttosto lunghi, specialmente ripetendoli 1000 volte, ognuno impiega qualche secondo per dare i risultati."<<endl<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
	VettoreLineare x(1);
	x.SetComponent(0, 280.);

	
	
	Calorimetro *kal1 = new Calorimetro(280.,323.15);
	
	RungeKutta myRK;

	

	//TGraph *ideale = new TGraph();

	double h = 0.1;
	int nstep = 0; 
	double t = 0.;
	double tmax = 400.;
	
	//PUNTO 1
	cout << "----------PUNTO 1----------"<<endl;
	out << "----------PUNTO 1----------"<<endl;
	while(t<tmax){
		
		//ideale->SetPoint(nstep, t, x.GetComponent(0) );
		x=myRK.Passo(t, x, h, kal1); 
		t += h;
		nstep++;
	} 
	double a = myRK.Passo(tmax, x, 0.1, kal1).GetComponent(0);
	cout << "Temperatura del bagno dopo 400s: " << setprecision(5) << a << "K." << endl;
	out << "Temperatura del bagno dopo 400s: " << setprecision(5) << a << "K." << endl;
	cout<<endl;
	out<<endl;
	//PUNTO 2
	cout << "----------PUNTO 2----------"<<endl;
	out << "----------PUNTO 2----------"<<endl;

	while(t<tmax){
		x=myRK.Passo(t, x, h/2., kal1); 
		t += h;
	} 

	double b = myRK.Passo(tmax, x, 0.05, kal1).GetComponent(0);
	
	cout << "L'errore commesso nell'integrazione dell'equazione e' o(h^4) e una stima puo' essere ottenuta calcolando la soluzione con un certo passo e poi con lo stesso passo dimezzato, l'errore a questo punto e' la differenza dei risultati per h^4. Risulta: "<< scientific << setprecision(2)<< abs(a-b)*16./15.<<endl;
	out << "L'errore commesso nell'integrazione dell'equazione e' o(h^4) e una stima puo' essere ottenuta calcolando la soluzione con un certo passo e poi con lo stesso passo dimezzato, l'errore a questo punto e' la differenza dei risultati per h^4. Risulta: "<< scientific << setprecision(2)<< abs(a-b)*pow(h,4)<<endl;	

	cout<<endl;
	out<<endl;
	//Punto 3
	cout << "----------PUNTO 3----------"<<endl;
	out << "----------PUNTO 3----------"<<endl;

	Random r(3);
	Vettore v(N);
	double eps1 = 0.1;
	t = 0.;
	for(int i=0; i<N; i++){
		x.SetComponent(0, r.BoxMuller(280., eps1));
		while(t<tmax+20){
		
			x=myRK.Passo(t, x, h, kal1); 
			t += h;
			nstep++;
		} 
		v.SetComponent(i,myRK.Passo(tmax, x, h, kal1).GetComponent(0));
		t = 0.;
	}

	double RMS1 = v.DevSt();

	cout<<"RMS della distribuzione della temperatura dopo 400s, incertezza di 0.1K su T10: " << scientific << setprecision(2)<< RMS1 << "K."<<endl;
	out<<"RMS della distribuzione della temperatura dopo 400s, incertezza di 0.1K su T10: " << scientific << setprecision(2)<< RMS1 << "K."<<endl;
	cout<<endl;
	out<<endl;	
	//PUNTO 4
	cout << "----------PUNTO 4----------"<<endl;
	out << "----------PUNTO 4----------"<<endl;

	double eps2 = 0.0005;
	t = 0.;
	for(int i=0; i<N; i++){
		x.SetComponent(0, 280.);
		kal1->SetK(r.BoxMuller(0.01, eps2));
		while(t<tmax+20){
		
			x=myRK.Passo(t, x, h, kal1); 
			t += h;
			nstep++;
		} 
		v.SetComponent(i,myRK.Passo(tmax, x, h, kal1).GetComponent(0));
		t = 0.;
	}
	
	double RMS2 = v.DevSt();
	
	cout<<"RMS della distribuzione della temperatura dopo 400s, incertezza di 0.0005 su K2: " << scientific << setprecision(2)<< RMS1 << "K."<<endl;
	out<<"RMS della distribuzione della temperatura dopo 400s, incertezza di 0.0005 su K2: " << scientific << setprecision(2)<< RMS1 << "K."<<endl;
	cout<<endl;
	out<<endl;	
	//PUNTO 5
	cout << "----------PUNTO 5----------"<<endl;
	out << "----------PUNTO 5----------"<<endl;

	//1-1
	t = 0.;
	for(int i=0; i<N; i++){
		x.SetComponent(0, r.BoxMuller(280., eps1));
		kal1->SetK(r.BoxMuller(0.01, eps2));
		while(t<tmax+20){
		
			x=myRK.Passo(t, x, h, kal1); 
			t += h;
			nstep++;
		} 
		v.SetComponent(i,myRK.Passo(tmax, x, h, kal1).GetComponent(0));
		t = 0.;
	}
	double RMS3 = v.DevSt();
	
	//2-1
		t = 0.;
	for(int i=0; i<N; i++){
		x.SetComponent(0, r.BoxMuller(280., 2*eps1));
		kal1->SetK(r.BoxMuller(0.01, eps2));
		while(t<tmax+20){
		
			x=myRK.Passo(t, x, h, kal1); 
			t += h;
			nstep++;
		} 
		v.SetComponent(i,myRK.Passo(tmax, x, h, kal1).GetComponent(0));
		t = 0.;
	}
	double RMS4 = v.DevSt();
	
	//1-2
		t = 0.;
	for(int i=0; i<N; i++){
		x.SetComponent(0, r.BoxMuller(280., eps1));
		kal1->SetK(r.BoxMuller(0.01, 2*eps2));
		while(t<tmax+20){
		
			x=myRK.Passo(t, x, h, kal1); 
			t += h;
			nstep++;
		} 
		v.SetComponent(i,myRK.Passo(tmax, x, h, kal1).GetComponent(0));
		t = 0.;
	}
	double RMS5 = v.DevSt();
	
	
	cout << "I valori dell'RMS relativi alle combinazioni di incertezze richieste sono rispetivamente:"<<endl;
	cout << "RMS1 = "<<RMS3<<endl;
	cout << "RMS2 = "<<RMS4<<endl;
	cout << "RMS3 = "<<RMS5<<endl;
	out << "I valori dell'RMS relativi alle combinazioni di incertezze richieste sono rispetivamente:"<<endl;
	out << "RMS1 = "<<RMS3<<endl;
	out << "RMS2 = "<<RMS4<<endl;
	out << "RMS3 = "<<RMS5<<endl;
	/*
	MyCanvas->cd();
	ideale->SetTitle("Andamento della temperatura del bagno");
	ideale->GetXaxis()->SetTitle("Tempo [s]");
	ideale->GetYaxis()->SetTitle("Temperatura [K]");
	ideale->Draw("AL");

	out.close();
	
	app.Run();
	*/
    
	return 0;
}

