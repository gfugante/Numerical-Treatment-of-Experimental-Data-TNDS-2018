#include <iostream>
#include "particelle.h"

using namespace std;

particelle::particelle(double massa, double carica){
	_massa=massa;
	_carica=carica;
}

particelle::~particelle(){ }

void particelle::print() const{
	cout<<"particelle: m="<<_massa<<", q="<<_carica<<endl;
}
