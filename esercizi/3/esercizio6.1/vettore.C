#include "vettore.h"
#include <iostream>

using namespace std;

Vettore::Vettore() {
	m_N=0;
}

Vettore::Vettore(unsigned int N) {
	m_N=N;
	m_v=new double [N];
	for(int i=0; i<N; i++)
	{
		m_v[i]=0;
	}
}

Vettore::~Vettore() {
	delete[] m_v;
}

void Vettore::SetComponent(unsigned int a, double b) {
	if(a>m_N-1){
		cout<<"Il vettore non ha un numero sufficiente di componenti "<<endl;
	}
	else
	m_v[a]=b;
}

double Vettore::GetComponent(unsigned int c) const {
	if(c>m_N-1){
		cout<<"Il vettore non ha un numero sufficiente di componenti "<<endl;
		return 0;
	}
	else
	return m_v[c];
}

Vettore::Vettore(const Vettore& v) {
	m_N=v.m_N;
	m_v=new double[m_N];
		for (int i=0; i<m_N; i++) {m_v[i]=v.m_v[i];}
}

Vettore& Vettore::operator=(const Vettore& v) {
	m_N=v.m_N;
	if(m_v) delete[] m_v;
	m_v= new double[m_N];
	for(int i=0; i<m_N; i++) {m_v[i]=v.m_v[i];}
	return *this;
}

