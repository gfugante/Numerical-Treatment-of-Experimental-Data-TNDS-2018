
#include "TH1F.h" 
#include "TCanvas.h"
#include "TGraph.h"
#include "TPad.h"
#include<iostream>
#include<fstream>
#include "TApplication.h"

using namespace std;
void CaricaVettInDinamico(ifstream& infile, double*& xv, double*& yv, int& n);

int main(int argc, char**argv){
	ifstream infile;
	int n=1;
	double*xv=new double[n];
	double*yv=new double[n];
	
	CaricaVettInDinamico(infile,xv,yv,n);

	 TApplication app("App",&argc, argv); 
	   TCanvas *c1 = new TCanvas("c1","punti",200,10,700,500);
		
	
	 TGraph *gr1=new TGraph(n, xv, yv); 
	
	TPad * p1=new TPad();
	c1->cd();
	p1->SetGrid();
	
	p1->Draw();
	p1->cd();

	p1->SetLogy();
	p1->SetLogx();
	 

	gr1->SetTitle("Andamento degli errori accumulati- RUNGE KUTTA");
	gr1->GetXaxis()->SetTitle("Passo h [s]");
	gr1->GetYaxis()->SetTitle("Errore accumulato sull'ultima stima [mm]");
	gr1->SetMarkerStyle(21);
	gr1->Draw("AP");
		


	 
	app.Run();
	  
	
	return 0;
}


void CaricaVettInDinamico(ifstream& infile, double*& xv, double*& yv, int& n){
	
	infile.open("erroriRungeKutta.dat");
	double x,y; 
	infile>>x>>y;
	
	
	xv[0]=x;
	yv[0]=y;

	infile>>x>>y;
	while(!infile.eof()){
		double*xv2=new double [n+1]; //
		double*yv2=new double [n+1]; 
		for(int i=0;i<n;i++){
			xv2[i]=xv[i];
			yv2[i]=yv[i];
			
		}
	

		delete [] xv;
		delete [] yv;

		xv=xv2;
		yv=yv2;

		xv[n]=x;
		yv[n]=y;
		
		n++;
		infile>>x>>y; }

	infile.close(); 
	infile.clear();

}
