#include <iostream>
#include "Esperimentoprisma.h"
#include "random.hpp"
#include "math.h"
#include <cmath>
#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "vettore.h"
#include "vettoredati.h"
#include "TH2F.h"

using namespace std;

int main(int argc, char** argv){
	TApplication app("app", &argc, argv);
	EsperimentoPrisma A;
	TH1F h0("Istogramma", "Theta 0", 100, (A.GetT0inp()-5.*A.GetSigmaT()), (A.GetT0inp()+5.*A.GetSigmaT()));
	TH1F h1("Istogramma", "Theta 1", 100, (A.GetT1inp()-5.*A.GetSigmaT()), (A.GetT1inp()+5.*A.GetSigmaT()));
	TH1F h2("Istogramma", "Theta 2", 100, (A.GetT2inp()-5.*A.GetSigmaT()), (A.GetT2inp()+5.*A.GetSigmaT()));
    vettoreDati v0(100000);
	vettoreDati v1(100000);
	vettoreDati v2(100000);
    vettoreDati dm1(100000);
    vettoreDati dm2(100000);
    vettoreDati n1(100000);
    vettoreDati n2(100000);
    vettoreDati a(100000);
    vettoreDati b(100000);
    double dm1v=2.*asin(A.GetN1in()*sin(0.5*A.GetAlpha()))-A.GetAlpha();
    double dm2v=2.*asin(A.GetN2in()*sin(0.5*A.GetAlpha()))-A.GetAlpha();
    for(int i=0; i<100000; i++){
		A.Esegui();
		A.Analizza();
		double t0=A.GetT0mis();
		double t1=A.GetT1mis();
		double t2=A.GetT2mis();
		h0.Fill(t0);
		h1.Fill(t1);
		h2.Fill(t2);
		v0.setComponent(i,t0);
		v1.setComponent(i,t1);
		v2.setComponent(i,t2);
        dm1.setComponent(i,t1-t0);
        dm2.setComponent(i, t2-t0);
        n1.setComponent(i, A.GetN1mis());
        n2.setComponent(i, A.GetN2mis());
        a.setComponent(i, A.GetAmis());
        b.setComponent(i, A.GetBmis());
    }
    v0.media();
    v1.media();
    v2.media();
    v0.devSt();
    v1.devSt();
    v2.devSt();
    dm1.media();
    dm2.media();
    dm1.devSt();
    dm2.devSt();
    n1.media();
    n2.media();
    n1.devSt();
    n2.devSt();
    a.media();
    a.devSt();
    b.media();
    b.devSt();
    TH1F h3("Istogramma", "Delta M1", 100, dm1v-5*dm1.getDevSt() ,dm1v+5*dm1.getDevSt());
    TH1F h4("Istogramma", "Delta M2", 100, dm2v-5*dm2.getDevSt() ,dm2v+5*dm2.getDevSt());
    TH1F h5("Istogramma", "N1", 100, A.GetN1in()-5*n1.getDevSt() ,A.GetN1in()+5*n1.getDevSt());
    TH1F h6("Istogramma", "N2", 100, A.GetN2in()-5*n2.getDevSt() ,A.GetN2in()+5*n2.getDevSt());
    TH1F h7("Istogramma", "A", 100, A.GetAin()-5*a.getDevSt(), A.GetAin()+5*a.getDevSt());
    TH1F h8("Istogramma", "B", 100, A.GetBin()-5*b.getDevSt(), A.GetBin()+5*b.getDevSt());
    TH2F b0("Istogramma Bidimensionale", "Residui Delta M", 100 ,-5*dm1.getDevSt(), 5*dm1.getDevSt(),100,-5*dm2.getDevSt(),5*dm2.getDevSt());
    TH2F b1("Istogramma Bidimensionale", "Residui N", 100, -5*n1.getDevSt(), 5*n1.getDevSt(), 100, -5*n2.getDevSt(), 5*n2.getDevSt());
    TH2F b2("Istogramma Bidimensionale", "Residui A,B", 100, -5*a.getDevSt(), 5*a.getDevSt(), 100, -5*b.getDevSt(), 5*b.getDevSt());
    for(int i=0; i<100000; i++)
    {
        h3.Fill(dm1.Getcomponente(i));
        h4.Fill(dm2.Getcomponente(i));
        h5.Fill(n1.Getcomponente(i));
        h6.Fill(n2.Getcomponente(i));
        h7.Fill(a.Getcomponente(i));
        h8.Fill(b.Getcomponente(i));
        b0.Fill(dm1.Getcomponente(i)-dm1v, dm2.Getcomponente(i)-dm2v);
        b1.Fill(n1.Getcomponente(i)-A.GetN1in(), n2.Getcomponente(i)-A.GetN2in());
        b2.Fill(a.Getcomponente(i)-A.GetAin(), b.Getcomponente(i)-A.GetBin());
    }
	cout<<"La media e la sigma di T0 e': "<<v0.getMedia()<<"  "<<v0.getDevSt()<<endl;
	cout<<"La media e la sigma di T1 e': "<<v1.getMedia()<<"  "<<v1.getDevSt()<<endl;
	cout<<"La media e la sigma di T2 e': "<<v2.getMedia()<<"  "<<v2.getDevSt()<<endl;
    cout<<"La media e la sigma di DM1 e': "<<dm1.getMedia()<<"  "<<dm1.getDevSt()<<endl;
    cout<<"La media e la sigma di DM2 e': "<<dm2.getMedia()<<"  "<<dm2.getDevSt()<<endl;
    cout<<"La media e la sigma di N1 è : "<<n1.getMedia()<<"  "<<n1.getDevSt()<<endl;
    cout<<"La media e la sigma di N2 è : "<<n2.getMedia()<<"  "<<n2.getDevSt()<<endl;
    cout<<"La media e la sigma di A è : "<<a.getMedia()<<"  "<<a.getDevSt()<<endl;
    cout<<"La media e la sigma di B è : "<<b.getMedia()<<"  "<<b.getDevSt()<<endl;
    cout<<"Il coeffficiente di correlazione lineare tra  DM è: "<<dm1.coeffCorrelazione(dm2)<<endl;
    cout<<"Il coeffficiente di correlazione lineare tra  N è: "<<n1.coeffCorrelazione(n2)<<endl;
    cout<<"Il coeffficiente di correlazione lineare tra  A,B è: "<<a.coeffCorrelazione(b)<<endl;
	TCanvas *c0=new TCanvas("c0", "c0");
	TCanvas *c1=new TCanvas("c1", "c1");
	TCanvas *c2=new TCanvas("c2", "c2");
    TCanvas *c3=new TCanvas("c3", "c3");
    TCanvas *c4=new TCanvas("c4", "c4");
    TCanvas *c5=new TCanvas("c5", "c5");
    TCanvas *c6=new TCanvas("c6", "c6");
    TCanvas *c7=new TCanvas("b0", "b0");
    TCanvas *c8=new TCanvas("b1", "b1");
    TCanvas *d0=new TCanvas("d0","d0");
    TCanvas *d1=new TCanvas("d1","d1");
    TCanvas *d2=new TCanvas("d2","d2");
	c0->cd();
	h0.Draw();
	c1->cd();
	h1.Draw();
	c2->cd();
	h2.Draw();
    c3->cd();
    h3.Draw();
    c4->cd();
    h4.Draw();
    c5->cd();
    h5.Draw();
    c6->cd();
    h6.Draw();
    c7->cd();
    h7.Draw();
    c8->cd();
    h8.Draw();
    d0->cd();
    b0.Draw();
    d1->cd();
    b1.Draw();
    d2->cd();
            b2.Draw();
	app.Run();
	
return 0;
}
