#include <iostream>
#include "particelle.h"
#include "elettrone.h"

using namespace std;

elettrone::elettrone(): particelle(9.1093826E-31, -1.60217653E-19) { }

elettrone::~elettrone() { }

void elettrone::print() const{
	cout<<"elettrone: m="<<_massa<<", q="<<_carica<<endl;
}
