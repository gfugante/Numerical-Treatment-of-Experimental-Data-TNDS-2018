#include <iostream>
#include "particelle.h"
#include "corpo_celeste.h"
#include "posizione.h"

using namespace std;

corpo_celeste::corpo_celeste(string nome, double massa, double raggio): particelle(massa, 0){
	_nome=nome;
	_raggio=raggio;
}

void corpo_celeste::setnome(string nome){
	_nome=nome;
}

void corpo_celeste::setraggio(double raggio){
	_raggio=raggio;
}

void corpo_celeste::setmassa(double massa){
	_massa=massa;
}

void corpo_celeste::setposizione(double x,double y,double z){
	_r.setposizione(x,y,z);
}

double corpo_celeste::getpotenziale(const posizione &r) const{
	return -6.67408e-11*_massa/getdistanza(r);
}

double corpo_celeste::getdistanza(const posizione &r) const{ //passo una posizione e mi restituisce la distanza dal corpo celeste
	return _r.distanza(r);
}

double corpo_celeste::getx() const{
	return _r.x();
}

double corpo_celeste::gety() const{
	return _r.y();
} 

double corpo_celeste::getz() const{
	return _r.z();
}

double corpo_celeste::getraggio() const{
	return _raggio;
}

string corpo_celeste::getnome() const{
	return _nome;
}

posizione corpo_celeste::getposizione() const{
	return _r;
}

void corpo_celeste::printposizione() const{
	cout<<"x="<<getx()<<", y="<<gety()<<", z="<<endl;
}

void corpo_celeste::print() const{
	cout<<"nome "<<_nome<<", m="<<_massa<<", r="<<_raggio<<endl;
}

corpo_celeste::~corpo_celeste() { }
