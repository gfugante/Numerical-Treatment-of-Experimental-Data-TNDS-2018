#include "vettore.h"

vettore::vettore(){
	m_N=0;
	m_v=0; 
}

vettore::vettore(unsigned int N){
	m_v=new double [N];
	for ( int i=0; i<N; i++){
		m_v[i]=0;
		m_N=N;
		}
}

vettore::~vettore(){
	delete [] m_v;
}

vettore::vettore (const vettore&V){
	m_N=V.m_N;
	m_v=new double [m_N];
	for(int i=0;i<m_N; i++){
		m_v[i]=V.m_v[i];}
}


vettore& vettore::operator=(const vettore&V){
	m_N=V.m_N;
	if (m_v) {delete[] m_v;}
	m_v=new double [m_N];
	for (int i=0; i<m_N; i++){
		m_v[i]=V.m_v[i];
		}
	return *this; //restituisce un puntatore all'oggetto
}

void vettore::switchComponent(unsigned int i,  unsigned int j){
	double c;
	c=getComponent(i);
	setComponent(i,getComponent(j));
	setComponent(j,c);
	return;
}
	


