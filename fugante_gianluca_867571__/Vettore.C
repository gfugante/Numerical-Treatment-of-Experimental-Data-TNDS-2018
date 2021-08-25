#include <iostream>
#include <cmath>
#include <iomanip>

#include "Vettore.h"

using namespace std;

Vettore::Vettore()
{
	_N = 0;
	_v = NULL;
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

	if (_v) delete[] _v; //libera la memoria per inserire i nuovi dati nel caso fosse occupata
	_v = new double[_N];

	for (int i = 0; i < _N; i++)
		this->SetComponent(i, V.GetComponent(i));

	return *this; 
}


void Vettore::SetComponent(unsigned int j, double a)
{
	_v[j] = a;
}

double Vettore::GetComponent(unsigned int j) const
{
	return _v[j];
}

void Vettore::print () const
{
	int width = static_cast<int> (log10(GetN()) + 1);
	
	for (unsigned int i = 0; i < GetN(); i++)
	{
		cout << setw(width) << i << ") " << GetComponent(i) << endl;
	}	
}

double Vettore::Varianza()const
{
	double sum = 0.;

	for(unsigned int i = 0; i < GetN(); i++)
		sum += pow(GetComponent(i) - Media(), 2);

	return sum/(GetN()-1);
}
double Vettore::DevSt()const
{
	return sqrt(Varianza());
}
double Vettore::Media()const
{
	double sum = 0.;

	for(unsigned int i = 0; i < GetN(); i++)
		sum += GetComponent(i);

	return sum / GetN();
}

double Vettore::Correlazione(const Vettore& V)const
{
	if(GetN()==V.GetN()){
		
		double mx = this->Media();
		double my = V.Media();
		Vettore tmp(*this);

		for(unsigned int i=0; i<tmp.GetN(); i++)
			tmp.SetComponent(i,pow(tmp.GetComponent(i),2));
		
		double mx2 = tmp.Media();
		tmp = V;
		for(unsigned int i=0; i<tmp.GetN(); i++)
			tmp.SetComponent(i,pow(tmp.GetComponent(i),2));
		
		double my2 = tmp.Media();
		tmp = V;
		for(unsigned int i=0; i<tmp.GetN(); i++)
			tmp.SetComponent(i,tmp.GetComponent(i)*this->GetComponent(i));

		double mxy = tmp.Media();
		double a = (mx2-pow(mx,2))*(my2-pow(my,2));
		if(a<0) a=a*(-1);
		return (mxy-(mx*my))/sqrt(a);
		
	}else return 0;
}

















