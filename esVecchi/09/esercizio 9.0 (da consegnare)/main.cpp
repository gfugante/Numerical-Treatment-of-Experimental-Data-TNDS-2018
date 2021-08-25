#include "EsperimentoPrisma.h"
#include <iostream>
#include <cmath>
#include <iomanip>


#include "TH1F.h" 
#include "TH2F.h" 
#include "TApplication.h"
#include "TCanvas.h" 

using namespace std;

double media(double*, unsigned int);
double devst(double*, unsigned int);

int main(int argc, char **argv){

    TApplication app("app", &argc, argv);
	unsigned  int N = 10000;

	double* t0 = new double [N];
	double* t1 = new double [N];
	double* t2 = new double [N];
	double* dm1 = new double [N];
	double* dm2 = new double [N];
	double* n1 = new double [N];
	double* n2 = new double [N];
	double* A = new double [N];
	double* B = new double [N];

	EsperimentoPrisma prisma;

	for(unsigned int i=0; i<N; i++){
		
		prisma.esegui();
		prisma.analizza();

		t0[i] = prisma.getT0();
		t1[i] = prisma.getT1();
		t2[i] = prisma.getT2();
		dm1[i] = prisma.getDm1();
		dm2[i] = prisma.getDm2();
		n1[i] = prisma.getN1();
		n2[i] = prisma.getN2();
		A[i] = prisma.getA();
		B[i] = prisma.getB();	
	}
	
	//medie
	double mediaT0 = media(t0,N);
	double mediaT1 = media(t1,N);
	double mediaT2 = media(t2,N);
	double mediaDm1 = media(dm1,N);
	double mediaDm2 = media(dm2,N);
	double mediaN1 = media(n1,N);
	double mediaN2 = media(n2,N);
	double mediaA = media(A,N);
	double mediaB = media(B,N);
	
	//deviazioni standard
	double devstT0 = devst(t0,N);
	double devstT1 = devst(t1,N);
	double devstT2 = devst(t2,N);
	double devstDm1 = devst(dm1,N);
	double devstDm2 = devst(dm2,N);
	double devstN1 = devst(n1,N);
	double devstN2 = devst(n2,N);
	double devstA = devst(A,N);
	double devstB = devst(B,N);

	TH1F _t0("t0", "Theta 0", 100, mediaT0-3*devstT0, mediaT0+3*devstT0);
	TH1F _t1("t1", "Theta 1", 100, mediaT1-3*devstT1, mediaT1+3*devstT1);
	TH1F _t2("t2", "Theta 2", 100, mediaT2-3*devstT2, mediaT2+3*devstT2);
	TH1F _dm1("dm1", "delta m1", 100, mediaDm1-3*devstDm1, mediaDm1+3*devstDm1);
	TH1F _dm2("dm2", "delta m2", 100, mediaDm2-3*devstDm2, mediaDm2+3*devstDm2);
	TH1F _n1("n1", "indice rifrazione 1", 100, mediaN1-3*devstN1, mediaN1+3*devstN1);
	TH1F _n2("n2", "indice rifrazione 2", 100, mediaN2-3*devstN2, mediaN2+3*devstN2);
	TH1F _A("A", "A", 100, mediaT0-3*devstT0, mediaA+3*devstA);
	TH1F _B("B", "B", 100, mediaT0-3*devstT0, mediaB+3*devstB);
	
	for(unsigned int i=0; i<N; i++)
	{
		_t0.Fill(t0[i]);
		_t1.Fill(t1[i]);
		_t2.Fill(t2[i]);
		_dm1.Fill(dm1[i]);
		_dm2.Fill(dm2[i]);
		_n1.Fill(n1[i]);
		_n2.Fill(n2[i]);
		_A.Fill(A[i]);
		_B.Fill(B[i]);
	}
	
	TH2F _dm("Correlazione delta", "Residui 2D", 100, mediaDm1-3*devstDm1, mediaDm1+3*devstDm1, 100, mediaDm2-3*devstDm2, mediaDm2+3*devstDm2);
	TH2F _n("Correlazione rifrazione", "Residui n", 100, mediaN1-3*devstN1, mediaN1+3*devstN1, 100, mediaN2-3*devstN2, mediaN2+3*devstN2);
	TH2F _AB("Correlazione A e B", "Residui A e B", 100, mediaA-3*devstA, mediaA+3*devstA, 100, mediaB-3*devstB, mediaB+3*devstB);
	
	double *dm = new double[N];
	double *n = new double[N];
	double *AB = new double[N];
	
	for (unsigned int i=0; i<N; i++)
	{
		dm[i]= dm1[i]*dm2[i];
		n[i]= n1[i]*n2[i];
		AB[i]= A[i]*B[i];
	}
	
	double corrDm = (media(dm, N)- mediaDm1*mediaDm2)/(devstDm1*devstDm2);
	double corrN = (media(n, N)- mediaN1*mediaN2)/(devstN1*devstN2);
	double corrAB = (media(AB, N)- mediaA*mediaB)/(devstA*devstB);
	
	/*cout << "Valori medi:" << endl;
	cout << "Theta 0:"*/
	
	delete[] t0;
	delete[] t1;
	delete[] t2;
	delete[] dm1;
	delete[] dm2;
	delete[] n1;
	delete[] n2;
	delete[] A;
	delete[] B;
	delete[] dm;
	delete[] n;
	delete[] AB;
	
	TCanvas *c1 = new TCanvas("c1","c1");
	TCanvas *c2 = new TCanvas("c2","c2");
	TCanvas *c3 = new TCanvas("c3","c3");
	TCanvas *c4 = new TCanvas("c4","c4");
	TCanvas *c5 = new TCanvas("c5","c5");
	TCanvas *c6 = new TCanvas("c6","c6");
	TCanvas *c7 = new TCanvas("c7","c7");
	TCanvas *c8 = new TCanvas("c8","c8");
	TCanvas *c9 = new TCanvas("c9","c9");
	TCanvas *c10 = new TCanvas("c10","c10");
	TCanvas *c11 = new TCanvas("c11","c11");
	TCanvas *c12 = new TCanvas("c12","c12");
	
    c1 -> cd();
    _t0.Draw();
    c2 -> cd();
    _t1.Draw();
    c3 -> cd();
    _t2.Draw();
    c4 -> cd();
    _dm1.Draw();
    c5 -> cd();
    _dm2.Draw();
    c6 -> cd();
    _n1.Draw();
    c7 -> cd();
    _n2.Draw();
    c8 -> cd();
    _A.Draw();
    c9 -> cd();
    _B.Draw();
    c10 -> cd();
    _dm.Draw();
    c11 -> cd();
    _n.Draw();
    c12 -> cd();
    _AB.Draw();
    

    app.Run();
    
    return 0;
}



double media(double* v, unsigned int N){

	double sum = 0.;
	for(unsigned int i=0; i<N; i++) sum+=v[i];

	return sum/N;

}

double devst(double* v, unsigned int N){

	double Media = media(v,N);
	double sum = 0.;
	for(unsigned int i=0; i<N; i++) sum+=pow(v[i]-Media,2);

	return sqrt(sum/N);
}


