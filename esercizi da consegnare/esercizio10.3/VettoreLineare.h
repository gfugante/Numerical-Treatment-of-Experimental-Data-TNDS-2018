#ifndef __VettoreLineare_h__
#define __VettoreLineare_h__

#include "Vettore.h"

class VettoreLineare : public Vettore
{
    //private:
        //Vettore *_v;
	
    public:
        VettoreLineare(unsigned int); //costruttore
        ~VettoreLineare(); //distruttore

        VettoreLineare operator+(const VettoreLineare&) const; //somma di vettori
        double operator*(const VettoreLineare&) const; //prodotto scalare
        VettoreLineare operator*(const double) const; //prodotto per uno scalare
        VettoreLineare operator-(const VettoreLineare&) const; //differenza
        VettoreLineare operator/(const double) const; //rapporto

        VettoreLineare operator+=(const VettoreLineare&) const; //sommatoria
        VettoreLineare operator-=(const VettoreLineare&) const;
        VettoreLineare operator*=(const double) const;
        VettoreLineare operator/=(const double) const;

	double Modulo();
        double Coseno(const VettoreLineare &) const;
	VettoreLineare Versore();

};

#endif
