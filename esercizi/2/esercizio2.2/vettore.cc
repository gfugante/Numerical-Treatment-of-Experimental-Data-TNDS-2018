#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "prototipi.h"
using namespace std;

struct vettore{
	unsigned int N;
	double* v;
};

struct vettore read(unsigned int N, const char* filename){

	struct vettore vett;
	vett.N=N;
	vett.v=new double[N];
	ifstream ingresso(filename);
	if(!ingresso){
		cerr<<"cannot open file"<<filename<<endl;
	}else{
		for(unsigned int i=0; i<N; i++){
			ingresso>>vett.v[i];
			if(ingresso.eof()){
				cerr<<"smetti di leggere dopo"<<i<<"entrate"<<endl;
				break;
			}
		}
	}
	return vett;
}

void stampa2(const struct vettore vett){
	ofstream out2("after.dat");
	int spessore=int(log10(vett.N)+1);
	for(unsigned int i=0; i<vett.N; i++){
		out2<<setw(spessore)<<i<<")"<<vett.v[i]<<endl;
	}
}

void stampa1(const struct vettore vett){
	ofstream out("before.dat");
	int spessore=int(log10(vett.N)+1);
	for(unsigned int i=0; i<vett.N; i++){
		out<<setw(spessore)<<i<<")"<<vett.v[i]<<endl;
	}
}

void selection_sort(const struct vettore vett){
	int i;
	for(i=0; i<vett.N-1; i++){
		for(int j=i+1; j<vett.N; j++){
			if(vett.v[j]<vett.v[i]){
				scambiabypointer(&vett.v[j], &vett.v[i]);
			}
		}
	}
return;
}
