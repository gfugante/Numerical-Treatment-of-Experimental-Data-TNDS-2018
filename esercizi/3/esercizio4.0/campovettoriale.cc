#include <iostream>
#include <cmath>
#include "campovettoriale.h"
#include "particelle.h"
#include "posizione.h"
using namespace std;

campovettoriale::campovettoriale(const posizione &a) : posizione (a.x(), a.y(), a.z()) {
	m_v[0]=0;
	m_v[1]=0;
	m_v[2]=0;
}

campovettoriale::campovettoriale(const posizione &a,double x, double y, double z) :posizione(a.x(), a.y(), a.z()) {
	m_v[0]=x;
	m_v[1]=y;
	m_v[2]=z;
}

double campovettoriale::modulo() const{
	return sqrt(m_v[0]*m_v[0]+m_v[1]*m_v[1]+m_v[2]*m_v[2]);
}

void campovettoriale::somma(const campovettoriale & F){
	m_v[0]=m_v[0]+F.getvx();
	m_v[1]=m_v[1]+F.getvx();
	m_v[2]=m_v[2]+F.getvx();
}
