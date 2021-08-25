#include "Vettore.h"
#include "VettoreLineare.h"
#include <iostream>
#include <cmath>


using namespace std;

VettoreLineare::VettoreLineare(unsigned int N) : Vettore(N){}

VettoreLineare VettoreLineare::operator+ (const VettoreLineare& b) const
{
	VettoreLineare r(getN());
	if(getN() != b.getN())
	{
		cerr<< "Errore: somma di due vettori di dimensione "<<getN()<<" e "<<b.getN()<<endl;
		return (-2);
	}
	for(unsigned int i=0; i<getN(); i++)
		r.setComponent(i,getComponent(i)+b.getComponent(i));

	return r;
}

double VettoreLineare::operator* (const VettoreLineare& b) const
{
	VettoreLineare r(getN());
	if(getN() != b.getN())
	{
		cerr<< "Errore: prodotto di due vettori di dimensione "<<getN()<<" e "<<b.getN()<<endl;
		return (-2);
	}

	double sum = 0.;
	for(unsigned int i=0; i<getN(); i++)
		sum += getComponent(i) * b.getComponent(i);

	return sum;
}

VettoreLineare VettoreLineare::operator* (const double b) const
{
	VettoreLineare r(getN());
	
	for(unsigned int i=0; i<getN(); i++)
		r.setComponent(i,getComponent(i)*b);

	return r;
}

VettoreLineare VettoreLineare::operator-(const VettoreLineare& b) const
{
    VettoreLineare r( getN() );

    if ( getN() != b.getN() )
    {
        cerr << "Errore: differenza di vettori di dimensione " << getN() << " e " << b.getN() << endl;
        return (-2);
    }

    for (unsigned int i = 0; i < getN(); i++)
        r.setComponent( i, getComponent(i) - b.getComponent(i) );

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
}

double VettoreLineare::Coseno(const VettoreLineare &a) const
{
    return ((*this) * a ) / (sqrt(a * a) * sqrt( (*this) * (*this) ) );
}

VettoreLineare VettoreLineare::Versore()
{
	VettoreLineare versor(getN());

	for (unsigned int i = 0; i < getN(); i++)
	{
		versor.setComponent( i, getComponent(i) / sqrt( (*this) * (*this) ) );
	}

	return versor;
}

double VettoreLineare::Modulo()
{
	return sqrt( (*this) * (*this) );
} 
