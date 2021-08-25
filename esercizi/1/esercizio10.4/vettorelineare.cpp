#include "vettorelineare.h"
#include <cmath>

vettoreLineare::vettoreLineare(unsigned int n):vettore(n){;}

vettoreLineare vettoreLineare::operator+(const vettoreLineare&v) const{
	vettoreLineare r(getN());
	if(getN()!=v.getN()){
		cerr<<"Errore: somma di vettori di dimensione "<<getN()<<"e "<<v.getN()<<endl;
	return -2;
	}
	for (unsigned int i=0;i<getN();i++){
		r.setComponent(i, getComponent(i)+v.getComponent(i));
		}
	return r;
}

double vettoreLineare::operator*(const vettoreLineare&b) const{
	double ps=0; //prodotto scalare
	if(getN()!=b.getN()){
		cerr<<"Errore: prodotto scalare di vettori di dimensione "<<getN()<<"e "<<b.getN()<<endl;
	return -2;
	}
	for (unsigned int i=0;i<getN();i++){
		ps+=getComponent(i)*b.getComponent(i);
		}
	return ps;
}

vettoreLineare vettoreLineare::operator*(const double a) const{
	vettoreLineare r(getN());
	for (unsigned int i=0;i<getN();i++){
		r.setComponent(i, a*getComponent(i));
		}
	return r;
}
	

