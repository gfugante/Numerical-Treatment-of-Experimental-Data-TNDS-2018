#include <iostream>
#include <cmath>
#include "vettore.h"
#include "VettoreLineare.h"

using namespace std;

VettoreLineare::VettoreLineare(unsigned int N): vettore(N){
}

VettoreLineare::~VettoreLineare(){}

    //somma tra vettori
VettoreLineare VettoreLineare::operator+ (const VettoreLineare& b) const
{
    VettoreLineare r( getN() );

    if ( getN() != b.getN() )
    {
        cerr << "Errore: somma di vettori di dimensione " << getN() << " e " << b.getN() << endl;
        return (-2);
    }

    for (unsigned int i = 0; i < getN(); i++)
        r.setComponenti( i, getComponenti(i) + b.getComponenti(i) );

    return r;
}

    //prodotto scalare
double VettoreLineare::operator*(const VettoreLineare& b) const
{
    VettoreLineare r( getN() );
    double sum = 0;

    if ( getN() != b.getN() )
    {
        cerr << "Errore: prodotto scalare di vettori di dimensione " << getN() << " e " << b.getN() << endl;
        return (-2);
    }

    for (unsigned int i = 0; i < getN(); i++)
        sum = sum + ( getComponenti(i) * b.getComponenti(i) );

    return sum;
}

    //prodotto di uno scalare per un vettore
VettoreLineare VettoreLineare::operator* (const double b) const
{
    VettoreLineare r( getN() );

    for (unsigned int i = 0; i < getN(); i++)
        r.setComponenti( i, getComponenti(i) * b );

    return r;
}


double VettoreLineare::Coseno(const VettoreLineare &a) const
{
    return ((*this) * a ) / (sqrt(a * a) * sqrt((*this) * (*this)));
}

VettoreLineare VettoreLineare::Versore()
{
	VettoreLineare versor(getN());

	for (unsigned int i = 0; i < getN(); i++)
	{
		versor.setComponenti(i, sqrt((*this) * (*this)));
	}

	return versor;
}
