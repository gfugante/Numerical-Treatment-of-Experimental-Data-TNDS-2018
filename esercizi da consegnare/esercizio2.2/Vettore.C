#include "Vettore.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Vettore read(unsigned int N, const char* filename){

	struct Vettore vett;
	vett.N = N;
	vett.v = new double[N];
	
	ifstream in(filename);
	if(!in){cout<<"Cannot open file"<<endl;}
	else{
		for(unsigned int i=0; i<N; i++){
			in>>vett.v[i];
	/*		if(in.eof){
				cout<<"Stop reading after "<<i<<" entries"<<endl;
				break;
			}*/
		}
	}
	in.close();
	return vett;
}



void print(const struct Vettore vett){

	int with = int(log10(vett.N)+1);
	for(unsigned int i=0; i<vett.N; i++){
		cout<<setw(with)<<i<<")"<<vett.v[i]<<endl;
	}
}


void print(const struct Vettore vett, const char* filename){

	int with = int(log10(vett.N)+1);

	ofstream out(filename);
	for(unsigned int i=0; i<vett.N; i++){
		out<<setw(with)<<i<<")"<<vett.v[i]<<endl;
	}
	out.close();
}




void selectionSort(double vett[], int N) {
    int minimo;

    for(unsigned int i=0; i<N; i++) {
        minimo = i;
        for(unsigned int j=i+1; j<N; j++) {
            if(vett[j] < vett[minimo])
                minimo = j;
        }
        scambia(&vett[i], &vett[minimo]);
    }
}


void selection_sort(struct Vettore vett){

    int minimo;

    for(unsigned int i=0; i<vett.N; i++) {
        minimo = i;
        for(unsigned int j=i+1; j<vett.N; j++) {
            if(vett.v[j] < vett.v[minimo])
                minimo = j;
        }
        scambia(&vett.v[i], &vett.v[minimo]);
    }
}



void scambia(double *a,double *b){
	double c;	
	c=*a;
	*a=*b;
	*b=c;
}









