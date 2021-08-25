/* 
si implementa l'integrazione della funzione sinx in un intervallo di estremi fissati (0, MPI) con il metodo dei trapezi e con precisione fissata all'interno della classe definita in precedenza che viene passata da terminale 
*/


#include "funzionebase.h"
#include "integrator.h"
#include <iostream>
#include <iomanip>
#include "sin.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, const char** argv){
	if (argc != 3){
		cerr<<"Usage: "<<argv[0]<<" <nstep> <precision>."<<endl;
		return -1;
		}
	double a=0; //estremi di integrazione
	double b= M_PI;
	
	double prec= atof(argv[2]);
	int nstep= atoi(argv[1]);
	int cifre_sig=-log10(prec);
	funzioneBase*seno=new Sin ();
	integral *integrale =new integral (a,b,seno);
	integral *integraletrap= new integral (a,b,seno, prec);
	//per confronto tra i tre metodi
	cout<<"L'integrale calcolato con midpoint: ";
	cout<< setprecision(12)<< integrale->midpoint(nstep)<<endl;
	cout<<"L'integrale calcolato con simpson: ";
	cout<< setprecision(12)<< integrale->simpson(nstep)<<endl;
	cout<<"L'integrale calcolato con il metodo dei trapezi"
	<<" a precisione fissata: ";
	cout<<fixed;
	cout<< setprecision(cifre_sig)<< integraletrap->trapezi()<<endl;
	
	return 0;
	
}


