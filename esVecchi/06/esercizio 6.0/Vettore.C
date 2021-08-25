#include <iostream>
#include "Vettore.h"

using namespace std;


Vettore::Vettore(){
	_N = 0;
	_v = 0;
}


Vettore::~Vettore(){delete []_v;}


Vettore::Vettore(unsigned int N){
	_v = new double[N];
	_N=N;
}


void Vettore::setComponente(unsigned int N, double a){

	if(N>_N) cout << "Errore: allungare il vettore prima di inserire la componente numero "<<N;
	else _v[N] = a;
}


double Vettore::getComponente(int N) const{

	if(N>_N) cout << "Errore: allungare il vettore prima di inserire la componente numero "<<N;
	else return _v[N];
}

Vettore::Vettore(const Vettore& V){
	_N = V._N;
	_v = new double[_N];
	for(int i =0; i<_N; i++) _v[i]=V._v[_N];
}


Vettore& Vettore::operator=(const Vettore& V){
	_N = V._N;
	if(_v) delete []_v;
	_v = new double[_N];
	for (int i=0; i<_N; i++) _v[i] = V._v[i];
	return *this;
}



