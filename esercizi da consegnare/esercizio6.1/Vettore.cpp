#include <iostream>
#include <cmath>
#include <iomanip>

#include "Vettore.h"

using namespace std;

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
 
Vettore::~Vettore()
{
	delete[] _v;
}

Vettore::Vettore(const Vettore& V)
{
	_N = V._N;
	_v = new double[_N];

	for (int i = 0; i < _N; i++)
		_v[i] = V._v[i];
}

	
Vettore& Vettore::operator=(const Vettore& V)
{
	_N = V._N;

	if (_v) delete[] _v; //libera la memoria per inserire i nuovi dati nel caso era occupata
	_v = new double[_N];

	for (int i = 0; i < _N; i++)
		_v[i] = V._v[i];

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

void Vettore::print ()
{
	int width = static_cast<int> (log10(GetN()) + 1);
	
	for (unsigned int i = 0; i < GetN(); i++)
	{
		cout << setw(width) << i << ") " << GetComponent(i) << endl;
	}	
}

double Vettore::Varianza()
{
	double sum = 0;

	for(unsigned int i = 0; i < GetN(); i++)
		sum += pow(GetComponent(i), 2) - pow(Media(), 2);

	return sum;
}

double Vettore::Media()
{
	double sum = 0;

	for(unsigned int i = 0; i < GetN(); i++)
		sum += GetComponent(i);

	return sum / GetN();
}
