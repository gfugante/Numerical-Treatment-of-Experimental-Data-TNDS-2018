#include "Particella.h"
#include "Posizione.h"
#include <string>
#include <cmath>


using namespace std;

Particella::Particella(){
	massa = 0;
	carica = 0;
}

Particella::Particella(double _massa, double _carica){
	massa = _massa;
	carica = _carica;
}

Particella::~Particella(){}

double Particella::getMassa() const{return massa;}
double Particella::getCarica() const{return carica;}

void Particella::print() const{
	cout<<"Particella:"<<endl;
	cout<<"massa = "<<massa<<endl;
	cout<<"carica = "<<carica<<endl;
}

Elettrone::Elettrone() : Particella(9.1093826E-31,-1.60217653E-19){}

void Elettrone::print() const{
	cout<<"Elettrone:"<<endl;
	cout<<"massa = "<<massa<<endl;
	cout<<"carica = "<<carica<<endl;
}


CorpoCeleste::CorpoCeleste(string _nome ,double _massa ,double _raggio) : Particella(_massa, 0){
	raggio = _raggio;
	massa = _massa;
	nome = _nome;
}

CorpoCeleste::~CorpoCeleste(){}

void CorpoCeleste::print() const{
	cout<<nome<<":"<<endl;
	cout<<"massa = "<<massa<<endl;
	cout<<"raggio = "<<raggio<<endl;
}

double CorpoCeleste::potenziale(Posizione R){
	 return (6.67408E-11*massa)/R.distanza(r);
}

