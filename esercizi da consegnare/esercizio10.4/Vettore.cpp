#include "Vettore.h"

Vettore::Vettore()
{
	_N = 0;
	_v = 0;
}
		
Vettore::Vettore (unsigned int n)
{
	_N = n;
	_v = new double[n];

	for (int i = 0; i < _N; i++)
		_v[i] = 0;
}

Vettore::Vettore(const Vettore& V)
{
	_N = V._N;
	_v = new double[_N];

	for (int i = 0; i < _N; i++)
		_v[i] = V._v[i];
}

Vettore::~Vettore()
{
	delete[] _v;
}

Vettore::Vettore(unsigned int n, double *v)
{
	_N = n;
	_v = v;
}

Vettore& Vettore::operator=(const Vettore& V)
{
	_N = V.GetN();

	if (_v) 
		delete[] _v; //libera la memoria per inserire i nuovi dati nel caso era occupata
	_v = new double[_N];

	for (int i = 0; i < _N; i++)
		_v[i] = V.GetComponent(i);

	return *this; //*this è un puntatore che indica all'oggetto al quale viene applicato l'operatore
}

void Vettore::SetComponent(unsigned int j, double a)
{
	_v[j] = a;
}

double Vettore::GetComponent(unsigned int j) const
{
	return _v[j];
}	
