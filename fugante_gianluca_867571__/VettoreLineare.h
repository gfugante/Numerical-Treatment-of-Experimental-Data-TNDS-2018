#ifndef __VettoreLineare_h__
#define __VettoreLineare_h__

#include "Vettore.h"

class VettoreLineare : public Vettore
{

	public:
		VettoreLineare(unsigned int);
		~VettoreLineare();

		VettoreLineare operator+(const VettoreLineare&) const; 
		double operator*(const VettoreLineare&) const; 
		VettoreLineare operator*(const double) const; 
		VettoreLineare operator-(const VettoreLineare&) const; 
		VettoreLineare operator/(const double) const; 

		VettoreLineare operator+=(const VettoreLineare&) const; 
		VettoreLineare operator-=(const VettoreLineare&) const;
		VettoreLineare operator*=(const double) const;
		VettoreLineare operator/=(const double) const;

		double Modulo();
		double Coseno(const VettoreLineare &) const;
		VettoreLineare Versore();

};

#endif
