#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

#include "Vettore.h"
#include "VettoreDati.h"
#include "Scambia.h"


using namespace std;

VettoreDati::VettoreDati(const char *filename)
{
	double x;
	unsigned int N;

	_vec = new Vettore(N);

	ifstream in (filename);
	in >> N;
	
	if (!in)
	{
		cout << "Impossibile aprire il file, programma interrotto. " << filename << endl;
		exit(-2);//break;
	}
	else
	{
		for (unsigned int i = 0; i < N; i++)
		{
			in >> x;
			_vec->SetComponent(i, x);
			if (!in)
			{
				cout << "Termine lettura dati dopo " << i << " inserimenti" << endl;
				break;
			}
		}
	}
}

VettoreDati::VettoreDati(unsigned int N, ifstream &in)
{
	_vec = new Vettore(N);
	double x;
		
	if (!in)
	{
		cout << "Impossibile aprire il file, programma interrotto. " << endl;
		exit (-2);//break;
	}
	else
	{
		for (unsigned int i = 0; i < N; i++)
		{
			in >> x;
			_vec->SetComponent(i, x);
			if (!in)
			{
				cout << "Termine lettura dati dopo " << i << " inserimenti" << endl;
				break;
			}
		}
	}

}

void VettoreDati::print () const
{
	unsigned int n = _vec->GetN();
	int width = int (log10(n) + 1);
	
	for (unsigned int i = 0; i < n; i++)
	{
		cout << setw(width) << i << ") " << _vec->GetComponent(i) << endl;
	}
}

void VettoreDati::print (ofstream& out) const
{
	int width = int (log10( _vec->GetN() ) + 1);
	
	for (unsigned int i = 0; i < _vec->GetN(); i++)
	{
		out << setw(width) << i << ") " << _vec->GetComponent(i) << endl;
	}
}

void VettoreDati::selectionSort ()
{
	unsigned int length = _vec->GetN();
	int i, j;
	for (int i = 0; i < length; i++)
	{

		for (int j = i+1; j < length; j++)
		{
			if (_vec->GetComponent(j) < _vec->GetComponent(i))
			{
				double c = _vec->GetComponent(i);
				_vec->SetComponent( i, _vec->GetComponent(j) );
				_vec->SetComponent(j, c);
				//scambiaByReference(_vec->GetComponent(i), _vec->GetComponent(j));
				/*_vec->SetComponent(i, u);
				_vec->SetComponent(i, v);*/
			}
		}
	}
}
