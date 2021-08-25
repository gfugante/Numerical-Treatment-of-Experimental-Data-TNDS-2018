#include <iostream>
#include <fstream>
#include "Vettore.h"
#include <cstdlib>
#include <time.h>


using namespace std;


int main(int argc, char** argv){


	//crea due file per verificare che il vettore sia stato riordinato, argv[1] è la lunghezza del vettore
	if(argc<3){
		cout<<"Usage: "<<argv[0]<<" <N points> <filename>"<<endl;

	}

	int N = atoi(argv[1]);
	struct Vettore v = read(N,argv[2]);
	print(v,"before.dat");
	selection_sort(v);
	print(v,"after.dat");




	//valuta il tempo di esecuzione per varie lunghezze del vettore, argv[1] è il numero di punti vlutati
	//lungo la funzione che descrive la crescita del tempo al variare della lunghezza del vettore

/*	if(argc<3){
		cout<<"Usage: "<<argv[0]<<" <N points> <filename>"<<endl;

	}
	int K = atoi(argv[1]);
	double *time = new double [K];
	double *numeri_riordinati = new double [K];
	
	clock_t t;

	for(int i=0; i<K; i++){

		int N = i*1E3;

		struct Vettore v = read(N,argv[2]);
				
		t=clock();
		selection_sort(v);
		t=clock()-t;
		time[i] = double(t)/CLOCKS_PER_SEC;
		numeri_riordinati[i] = N;
		delete[] v.v;
	}


	ofstream output("data_time.txt");
	output<<"#N_points	#Time"<<endl;
	for(int i=0; i<K; i++){
		output<<numeri_riordinati[i]<<"		"<<time[i]<<endl;
	}
	output.close();

	delete[] time;
	delete[] numeri_riordinati;
*/
}


