#include <iostream>
#include "vettore.h"

using namespace std;

vettore::vettore(){
	_N=0;
	_v= new double[_N];
	for(int i=0; i<_N; i++) {
		_v[i]=0;
	}
}

vettore::vettore(unsigned int N){
	_N=N;
	_v= new double[_N];
	for(int i=0; i<_N; i++) {
		_v[i]=0;
	}
}

vettore::~vettore(){
	delete[] _v;
}

vettore::vettore(const vettore & V){
	_N=V._N;
	_v= new double[_N];
	for(int i=0; i<_N; i++){
		_v[i]=V._v[i];
	}
}

vettore & vettore::operator=(const vettore & V){
	_N=V._N;
	if(_v){delete[] _v;}
	_v= new double [_N];
	for(int i=0; i<_N; i++){ _v[i]=V._v[i];}
	return * this;
}

void vettore::setComponenti(unsigned int j, double k){
	if(j<_N){
		_v[j]=k;
	}
	return;
}

double vettore::getComponenti(unsigned int j) const{
	return _v[j];
}
