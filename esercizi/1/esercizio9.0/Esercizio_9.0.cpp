//Questo programma simula N volte l'esperimento della misura dell'indice di rifrazione del prisma.

#include <iomanip>
#include "vettoredati.h"
#include "esperimentoprisma.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include <iostream>
#define N 10000

using namespace std;

int main(int argc, char**argv){	

	esperimentoPrisma p;
	TApplication app("app", &argc, argv);
	TH1F *h0=new TH1F ("Theta0", "titolo", 100,p.getT0input()-5*p.getSigmat(), p.getT0input()+5*p.getSigmat());
	TH1F *h1=new TH1F ("Theta1", "titolo", 100,p.getT1input()-5*p.getSigmat(),p.getT1input()+5*p.getSigmat());
	TH1F *h2=new TH1F ("Theta2", "titolo", 100,p.getT2input()-5*p.getSigmat(),p.getT2input()+5*p.getSigmat()); 

	vettoreDati t0(N);
	vettoreDati t1(N);
	vettoreDati t2(N);
	vettoreDati n1(N);		
	vettoreDati n2(N);
	vettoreDati A(N);
	vettoreDati B(N);

	//Parte 1 
	//(Con t1 si indica l'angolo misuratorelativo a lambda1, con t2 si indica l'angolo misuratorelativo a lambda2)
	
	for (int i=0; i<N; i++){
		p.execute();
		t0.setComponent(i,p.getT0misurato());
		h0->Fill(t0.getComponent(i));
		t1.setComponent(i,p.getT1misurato());
		h1->Fill(t1.getComponent(i));
		t2.setComponent(i,p.getT2misurato());
		h2->Fill(t2.getComponent(i));
		p.analize();
		n1.setComponent(i,p.getN1misurato());
		n2.setComponent(i,p.getN2misurato());
		A.setComponent(i,p.getAmisurato());
		B.setComponent(i,p.getBmisurato());
	}
	t0.media();
	t1.media();
	t2.media();
	t0.devSt();
	t1.devSt();
	t2.devSt();
	
	cout<<endl;
	cout<<setprecision(5);
	cout<<"Parte1 :"<<endl;
	cout<<"media t0="<<t0.getMedia()<<" "<<"media t1="<<t1.getMedia()<<" "<<"media t2="<<t2.getMedia()<<endl;
	cout<<setprecision(1);
	cout<<"dev.st t0="<<t0.getDevSt()<<" "<<"dev.st t1="<<t1.getDevSt()<<" "<<"dev.st t2="<<t2.getDevSt()<<endl;

	TCanvas*c0=new TCanvas("c0","c0", 1200, 600);
	c0->Divide(3,1);
	c0->cd(1);
	h0->Draw();
	h0->SetTitle("Distribuzione Theta 0");
	h0->GetXaxis()->SetTitle("Valore misurato (rad)");
	h0->GetYaxis()->SetTitle("Frequenza");	
	c0->cd(2);
	h1->Draw();
	h1->SetTitle("Distribuzione Theta 1");//Angolo relativo a lambda1
	h1->GetXaxis()->SetTitle("Valore misurato (rad)");
	h1->GetYaxis()->SetTitle("Frequenza");	
	c0->cd(3);
	h2->Draw();
	h2->SetTitle("Distribuzione Theta 2");//Angolo relativo a lambda1
	h2->GetXaxis()->SetTitle("Valore misurato (rad)");
	h2->GetYaxis()->SetTitle("Frequenza");	
	
	//Parte 2
	vettoreDati dm1(N);
	vettoreDati dm2(N);
	
	for (int i=0; i<N; i++){
		dm1.setComponent(i,t1.getComponent(i)-t0.getComponent(i));
		dm2.setComponent(i,t2.getComponent(i)-t0.getComponent(i));
	}
	
	dm1.media();
	dm2.media();
	dm2.devSt();
	dm1.devSt();
	n1.media();
	n1.devSt();
	n2.media();
	n2.devSt();
	A.media();
	A.devSt();
	B.media();
	B.devSt();
	
	//Istogrammi per i d(lambda)
	TH1F *hdm1=new TH1F ("Errori d1", "Errori d1", 100,-5*dm1.getDevSt(),5*dm1.getDevSt());
	TH1F *hdm2=new TH1F ("Errori d2", "Errori d2", 100,-5*dm2.getDevSt(),5*dm2.getDevSt()); 
	//Istogrammi per gli n(lambda)
	TH1F *hn1=new TH1F ("Errori n1", "Errori n1", 100,-5*n1.getDevSt(),5*n1.getDevSt());
	TH1F *hn2=new TH1F ("Errori n2", "Errori n2", 100,-5*n2.getDevSt(),5*n2.getDevSt());
	////Istogrammi per A e B
	TH1F *ha=new TH1F ("Errori A", "Errori A", 100,-5*A.getDevSt(),5*A.getDevSt());
	TH1F *hb=new TH1F ("Errori B", "Errori B", 100,-5*B.getDevSt(),5*B.getDevSt());

	for (int i=0; i<N; i++){
		hdm1->Fill(dm1.getComponent(i)-(p.getT1input()-p.getT0input()));
		hdm2->Fill(dm2.getComponent(i)-(p.getT2input()-p.getT0input()));
		hn1->Fill(n1.getComponent(i)-p.getN1input());
		hn2->Fill(n2.getComponent(i)-p.getN2input());
		ha->Fill(A.getComponent(i)-p.getAinput());
		hb->Fill(B.getComponent(i)-p.getBinput());
	}
	
	//Istogrammi bidimensionali
	TH2F *hdm=new TH2F ("2D dm", "titolo", 10000,dm1.getMedia()-5*dm1.getDevSt(),dm1.getMedia()+5*dm1.getDevSt(),10000,dm2.getMedia()-5*dm2.getDevSt(),dm2.getMedia()+5*dm2.getDevSt());
	TH2F *hn=new TH2F ("2D n", "n", 10000,n1.getMedia()-5*n1.getDevSt(),n1.getMedia()+5*n1.getDevSt(),10000,n2.getMedia()-5*n2.getDevSt(),n2.getMedia()+5*n2.getDevSt());
	TH2F *hab=new TH2F ("2D AB", "AB", 10000,A.getMedia()-5*A.getDevSt(),A.getMedia()+5*A.getDevSt(),10000,B.getMedia()-5*B.getDevSt(),B.getMedia()+5*B.getDevSt());
	
	for (int i=0; i<N; i++){
	hdm->Fill(dm1.getComponent(i), dm2.getComponent(i));
	hn->Fill(n1.getComponent(i), n2.getComponent(i));
	hab->Fill(A.getComponent(i), B.getComponent(i));
	}

	TCanvas*c1=new TCanvas("c1","c1", 1200, 600);
	c1->Divide(3,1);
	c1->cd(1);
	hdm1->Draw();
	hdm1->SetTitle("Differenza tra dm(lambda1) atteso e misurato");
	hdm1->GetXaxis()->SetTitle("Errore (rad)");
	hdm1->GetYaxis()->SetTitle("Frequenza");
	c1->cd(2);
	hdm2->Draw();
	hdm2->SetTitle("Differenza tra dm(lambda2) atteso e misurato");
	hdm2->GetXaxis()->SetTitle("Errore (rad)");
	hdm2->GetYaxis()->SetTitle("Frequenza");
	c1->cd(3);
	hdm->Draw();
	hdm->SetTitle("Residui 2D");
	hdm->GetXaxis()->SetTitle("Errore dm1 (rad)");
	hdm->GetYaxis()->SetTitle("Errore dm2 (rad)");
	

	TCanvas*c2=new TCanvas("c2","c2", 1200, 600);
	c2->Divide(3,1);
	c2->cd(1);
	hn1->Draw();
	hn1->SetTitle("Differenza tra n(lambda1) atteso e misurato");
	hn1->GetXaxis()->SetTitle("Errore");
	hn1->GetYaxis()->SetTitle("Frequenza");
	c2->cd(2);
	hn2->Draw();
	hn2->SetTitle("Differenza tra A atteso e misurato");
	hn2->GetXaxis()->SetTitle("Errore");
	hn2->GetYaxis()->SetTitle("Frequenza");
	c2->cd(3);
	hn->Draw();
	hn->SetTitle("Residui 2D");
	hn->GetXaxis()->SetTitle("Errore n(lambda1)");
	hn->GetYaxis()->SetTitle("Errore n(lambda2)");
	
	TCanvas*c3=new TCanvas("c3","c3", 1200, 600);
	c3->Divide(3,1);
	c3->cd(1);
	ha->Draw();
	ha->SetTitle("Differenza tra A atteso e misurato");
	ha->GetXaxis()->SetTitle("Errore");
	ha->GetYaxis()->SetTitle("Frequenza");
	c3->cd(2);
	hb->Draw();
	hb->SetTitle("Differenza tra B atteso e misurato");
	hb->GetXaxis()->SetTitle("Errore (m^2)");
	hb->GetYaxis()->SetTitle("Frequenza");
	c3->cd(3);
	hab->Draw();
	hab->SetTitle("Residui 2D");
	hab->GetXaxis()->SetTitle("Errore A");
	hab->GetYaxis()->SetTitle("Errore B (m^2)");
	
	//Calcolo dei coefficienti di correlazione
	double coeffcorr;
	cout<<setprecision(3);
	cout<<"Parte 2:"<<endl;
	coeffcorr=dm1.coeffCorrelazione(dm2);
	cout<<"Coefficiente di correlazione tra dm1 e dm2: "<<coeffcorr<<endl;
	coeffcorr=n1.coeffCorrelazione(n2);
	cout<<"Coefficiente di correlazione tra n1 e n2: "<<coeffcorr<<endl;
	coeffcorr=A.coeffCorrelazione(B);
	cout<<"Coefficiente di correlazione tra A e B: "<<coeffcorr<<endl;

	app.Run(); 
	return 0;
}
	
