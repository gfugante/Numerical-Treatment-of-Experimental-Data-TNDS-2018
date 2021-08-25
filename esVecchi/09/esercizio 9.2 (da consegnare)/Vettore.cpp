#include "Vettore.h"
#include <fstream>
#include <string>
#include <iostream>


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


double Vettore::getComponente(unsigned int N) const{

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


VettoreDati::VettoreDati(unsigned int n ,string file) : Vettore(n){

	ifstream input("/home/comune/labTNDS_aa1112_materiale/lezione2/data.txt");
	if(!input) cout<<"Impossibile aprire il file "<<endl;	

	double a;
	input>>a;

	for(unsigned int i=0; i<n; i++){
		setComponente(i,a);
		if(input.eof()) break;	
		input>>a;
	}
	
	input.close();
}


void VettoreDati::print(string file){
	ofstream output(file.c_str());
	for(unsigned int i=0; i<getN(); i++) output<<getComponente(i)<<endl;
	output.close();
}


void VettoreDati::print() const{
	for(unsigned int i=0; i<getN(); i++) cout<<getComponente(i)<<endl;
}


void VettoreDati::sort(){
	unsigned int minimo;

	for(unsigned int i=0; i<getN(); i++) {
	    minimo = i;
	    for(unsigned int j=i+1; j<getN(); j++) {
	        if(getComponente(j) < getComponente(minimo))
	            minimo = j;
	    }
		double c;	
		c=getComponente(i);
		setComponente(i,getComponente(minimo));
		setComponente(minimo,c);
	}
}


VettoreDati::~VettoreDati(){delete []_v;}

