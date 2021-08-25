#include "Vettore.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

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

void VettoreDati::sortQ(){quicksort(0,getN()-1);}

void VettoreDati::quicksort(unsigned int primo, unsigned int ultimo){
	if(primo>ultimo || ultimo>=getN()) return;
	if(ultimo-primo<=1){
		if(getComponente(primo)>getComponente(ultimo)) scambia(primo, ultimo);
		return;
	}
	double pivot = getComponente((primo+ultimo)/2);
	unsigned int basso = primo, alto = ultimo;
	while(basso<alto){
		while(getComponente(basso)<pivot) basso++;
		while(getComponente(alto)>pivot) alto--;
		if(basso<alto){scambia(basso,alto);basso++;}	
	}
	quicksort(primo,basso-1);
	quicksort(basso,ultimo);
}

void VettoreDati::scambia(unsigned int primo, unsigned int ultimo){
	double c = getComponente(primo);
	setComponente(primo,getComponente(ultimo));
	setComponente(ultimo,c);
}

double VettoreDati::media() const{
	double somma =0.;
	for(unsigned int i=0;i<getN();i++) somma += getComponente(i);
	return somma/getN();
}

double VettoreDati::varianza() const{
	double somma =0.;
	double Media = media();
	for(unsigned int i=0;i<getN();i++) somma += pow((getComponente(i)-Media),2);
	return somma/getN();
}

double VettoreDati::devst() const{
	return sqrt(varianza());
}

double VettoreDati::devstmedia() const{
	return sqrt(varianza()/getN());
}

double VettoreDati::coefficenteR(VettoreDati v) const{
	if(v.getN()==this->getN()){
		double sommex,sommey,sommex2,sommey2,sommexy;
		sommex =0.;sommey =0.;sommex2 =0.;sommey2 =0.;sommexy =0.;

		for(unsigned int i=0; i<this->getN();i++) sommex+=this->getComponente(i);
		for(unsigned int i=0; i<v.getN();i++) sommey+=v.getComponente(i);
		for(unsigned int i=0; i<this->getN();i++) sommex2+=pow(this->getComponente(i),2);
		for(unsigned int i=0; i<v.getN();i++) sommey2+=pow(v.getComponente(i),2);
		for(unsigned int i=0; i<v.getN();i++) sommexy+=(this->getComponente(i))*v.getComponente(i);

		double mediax=this->media();
		double mediay=v.media();
		double sommescarti2x = 0.;
		double sommescarti2y = 0.;

		for(unsigned int i=0; i<this->getN();i++) sommescarti2x+=pow(this->getComponente(i)-mediax,2);
		for(unsigned int i=0; i<v.getN();i++) sommescarti2y+=pow(v.getComponente(i)-mediay,2);

		return (sommexy-(sommex*sommey))/sqrt(sommescarti2x*sommescarti2y); 		
	}else return 30000;

}

