/*
Implementazione con il metodo di Simpson con un numero di passi definito lanciato da terminale, produce un output con la precisione raggiunta in funzione del numero di passi 

Si integra la funzione seno nell'intervallo (0, M_PI)



*/


#include "integrator.h"
#include <iostream>
#include <iomanip>
#include "sin.h"
#include <fstream>
#include <cstdlib>



using namespace std;

int main(int argc, const char** argv){
	if (argc != 2){
		cerr<<"Usage: "<<argv[0]<<" <nstep>."<<endl;
		return -1;
		}
	double a=0; //estremi di integrazione
	double b= M_PI; //
	
	int nstep= atoi(argv[1]);
	
	funzioneBase*seno=new Sin ();
	integral *integrale =new integral (a,b,seno);
	
	cout<< setprecision(12)<<"Il valore dell'integrale calcolato con midpoint con i passi dati: "<< integrale->midpoint(nstep)<<endl; 
	cout<< setprecision(12)<<"Il valore dell'integrale calcolato con simpson con i passi dati: "<< integrale->simpson(nstep)<<endl; 

	ofstream outfile;
	outfile.open("integral_table.dat");
	outfile<<fixed;
	outfile<<setprecision(15);
	

//per la tabella
	double imid,isim,ivero;

	ivero=(-cos(b)+cos(a));

	for(int i=0;i<15;i++){
	
	 /*outfile<<2*nstep<<setw(5)<<(-cos(b)+cos(a))<<setw(30)<<integrale->midpoint(nstep)<<setw(30)<<((integrale->midpoint(nstep))-(-cos(b)+cos(a)))<<setw(30)<<integrale->simpson(nstep)<<setw(30)<<((integrale->simpson(nstep))-(-cos(b)+cos(a)))<<"\t"<<integrale->getH()<<endl;
	nstep=nstep*2; */
	imid=integrale->midpoint(nstep);
	isim=integrale->simpson(nstep);

	outfile<<nstep<<"\t"
		<<ivero<<"\t" 				//valore vero
		<<imid<<"\t"				//valore midp
		<<(imid-ivero)<<"\t"			//differenza midp-vero
		<<isim<<"\t"				//valore simpson
		<<(isim-ivero)<<"\t"			//differenza simpson-vero
		<<integrale->getH()<<endl;		//passo H 
	nstep=nstep*2;

	}

	outfile.close();
	outfile.clear();
	
	
}


