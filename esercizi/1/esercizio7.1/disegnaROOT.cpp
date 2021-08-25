//disegna due grafici a partire dal file

#include "TH1F.h" 
#include "TCanvas.h"
#include "TGraph.h"
#include "TPad.h"
#include<iostream>
#include<fstream>
#include "TApplication.h"
#include "TF1.h"
#include "TFormula.h"

using namespace std;
void CaricaVettInDinamico(ifstream& infile, double*& xv, double*& yv, int& n);

int main(int argc, char**argv){
	ifstream infile;
	infile.open("integral_table.dat");
	double n1,n2,n3,n4,n5,n6,n7;

	 TApplication app("App",&argc, argv); 
	   TCanvas *c1 = new TCanvas("c1","c1",500,10,1000,500);
		c1->Divide(2,1);
		
	
	 TGraph *gr1=new TGraph(); 
	 TGraph *gr2=new TGraph(); 
	int i=1;
	
	infile>>n1>>n2>>n3>>n4>>n5>>n6>>n7;
	while(!infile.eof()){
		
		gr1->SetPoint(i,n7,n4);// per midpoint
		gr2->SetPoint(i,n7,n6);// per simpson
		infile>>n1>>n2>>n3>>n4>>n5>>n6>>n7;
		i++;
	}

	infile.close(); 
	infile.clear();

	TPad * p1=new TPad();
	TPad * p2=new TPad();
	c1->cd(1);
	p1->SetGrid();

	p1->Draw();
	p1->cd();

	gr1->SetTitle("Andamento dei delta midp-vero in funzione di h");
	gr1->GetXaxis()->SetTitle("Passo h");
	gr1->GetYaxis()->SetTitle("Delta midpoint-vero");

	gr1->Draw("AP*");
	
	
	

	//p1->SetLogy();
	//p1->SetLogx();
	
	c1->cd(2);
	
	p2->SetGrid();
	p2->Draw();
	p2->cd();

	
	gr2->SetTitle("Andamento dei delta simps-vero in funzione di h");
	gr2->GetXaxis()->SetTitle("Passo h");
	gr2->GetYaxis()->SetTitle("Delta simpson-vero");

	gr2->Draw("AP*");
		


	 
	app.Run();
	  
	
	return 0;
}


