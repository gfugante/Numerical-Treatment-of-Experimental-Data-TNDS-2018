/* Il programma riempie un array di N posizioni con i primi N valori letti dal file e ordina il vettore usando l'algoritmo selection sort.
N ed il nome del file sono passati al programma da riga di comando.
Si stampa su file l'array prima (before.dat) e dopo (after.dat) l'ordinamento.
Si esegue il codice variando N da terminale, da qualche centinaia a qualche decina di migliaia per valutarne il
tempo di esecuzione, salvati in data_time.dat e plottati con ./disegnaROOT
*/


#include <iostream>
#include "vettore.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;


int main(int argc, char **argv){
	if(argc!=3){
		cerr<<"Usage: "<<argv[0]<<" <N_Values> <filename>"<<endl;
		return -1; }
	
	unsigned int N=atoi(argv[1]); //contenuta in cstdlib...converte in int atof converte in float
	struct vettore v=read(N, argv[2]);
	ofstream outb,outa;
	outb.open("before.dat");
	
	cout<<"Before sorting: "<<endl;
	print(v); //stampa su terminale
	print(v,outb); //stampa su file 

	outb.close();
	outb.clear();

	clock_t t;
	t=clock(); 
	selection_sort(v);
	t=clock()-t;

	cout<<endl<<endl;

	outb.open("after.dat");

	cout<<"After sorting: "<<endl;
	
	print(v);
	print(v,outa);
	delete [] v.v;

	outa.close();
	outa.clear();

	

	ofstream outfile;
	outfile.open("data_time.dat",ofstream::app);

	
	float time;
	time=static_cast<float>(t)/CLOCKS_PER_SEC;
	cout<<endl<<"TIME:"<<time<<endl;
	outfile<<N<<"\t"<<time<<endl;

	outfile.close();
	outfile.clear();
	return 0;	


}


