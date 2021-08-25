#include <iostream>
#include <fstream>
#include "vettore.h"
#include "vettoredati.h"

void scambiabypointer(double *, double *);

using namespace std;

vettoredati::vettoredati(unsigned int N, const char * filename): vettore(N){
	ifstream ingresso(filename);
	for(unsigned int i=0; i<_N; i++){
		if(ingresso.eof()){break;}
		ingresso>>_v[i];

	}
}

vettoredati::~vettoredati() {
	delete[] _v;
}

void vettoredati::print(){
	for(int i=0; i<_N; i++){
		cout<<i<<")"<<_v[i]<<endl;
	}
}

void vettoredati::print(const char * output){
	ofstream uscita(output);
	for(int i=0; i<_N; i++){
		uscita<<_v[i]<<endl;
	}
}

void vettoredati::ordina(){
	int i;
	for(i=0; i<_N-1; i++){
		for(int j=i+1; j<_N; j++){
			if(_v[j]<_v[i]){
				scambiabypointer(& _v[j], & _v[i]);
			}
		}
	}
	return;
}

void scambiabypointer(double * a, double * b){
	double c;
	c=*a;
	*a=*b;
	*b=c;
	return;
}








