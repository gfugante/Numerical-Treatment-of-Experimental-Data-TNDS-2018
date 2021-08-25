#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Vettore.h"
#include "VettoreLineare.h"

using namespace std;

VettoreLineare::VettoreLineare(unsigned int N): Vettore(N)
{}

VettoreLineare::~VettoreLineare()
{}

VettoreLineare VettoreLineare::operator+ (const VettoreLineare& b) const
{
    VettoreLineare r( GetN() );

    if ( GetN() != b.GetN() )
    {
        cerr << "Errore: somma di vettori di dimensione " << GetN() << " e " << b.GetN() << endl;
        return (-2);
    }

    for (unsigned int i = 0; i < GetN(); i++)
        r.SetComponent( i, GetComponent(i) + b.GetComponent(i) );

    return r;
}

    //prodotto scalare
double VettoreLineare::operator*(const VettoreLineare& b) const
{
    VettoreLineare r( GetN() );
    double sum = 0;

    if ( GetN() != b.GetN() )
    {
        cerr << "Errore: prodotto scalare di vettori di dimensione " << GetN() << " e " << b.GetN() << endl;
        return (-2);
    }

    for (unsigned int i = 0; i < GetN(); i++)
        sum = sum + ( GetComponent(i) * b.GetComponent(i) );

    return sum;
}

    //prodotto di uno scalare per un vettore
VettoreLineare VettoreLineare::operator*(const double b) const
{
    VettoreLineare r( GetN() );

    for (unsigned int i = 0; i < GetN(); i++)
        r.SetComponent( i, GetComponent(i) * b );

    return r;
}

    //differenza
VettoreLineare VettoreLineare::operator-(const VettoreLineare& b) const
{
    VettoreLineare r( GetN() );

    if ( GetN() != b.GetN() )
    {
        cerr << "Errore: differenza di vettori di dimensione " << GetN() << " e " << b.GetN() << endl;
        exit (-2);
    }

    for (unsigned int i = 0; i < GetN(); i++)
        r.SetComponent( i, GetComponent(i) - b.GetComponent(i) );

    return r;
}

    //rapporto
VettoreLineare VettoreLineare::operator/(const double c) const
{
    return (*this) * (1./c);
}

    //sommatoria
VettoreLineare VettoreLineare::operator+=(const VettoreLineare& b) const
{
    return (*this) + b;
}

VettoreLineare VettoreLineare::operator-=(const VettoreLineare& b) const
{
    return (*this) - b;
}

VettoreLineare VettoreLineare::operator*=(const double b) const
{
    return (*this) * b;
}

VettoreLineare VettoreLineare::operator/=(const double b) const
{
    return (*this) / b;
}//*/

double VettoreLineare::Coseno(const VettoreLineare &a) const
{
    return ((*this) * a ) / (sqrt(a * a) * sqrt( (*this) * (*this) ) );
}

VettoreLineare VettoreLineare::Versore()
{
	VettoreLineare versor(GetN());

	for (unsigned int i = 0; i < GetN(); i++)
	{
		versor.SetComponent( i, GetComponent(i) / sqrt( (*this) * (*this) ) );
	}

	return versor;
}

double VettoreLineare::Modulo()
{
	return sqrt( (*this) * (*this) );
} 
