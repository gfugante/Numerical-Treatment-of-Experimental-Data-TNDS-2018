#ifndef __VettoreLineare_h__
#define __VettoreLineare_h__

#include "vettore.h"

class VettoreLineare : public vettore
{
    public:
        VettoreLineare(unsigned int); //costruttore
        ~VettoreLineare(); //distruttore

        VettoreLineare operator+(const VettoreLineare&) const; //somma di vettori
        double operator*(const VettoreLineare&) const; //prodotto scalare
        VettoreLineare operator*(const double) const; //prodotto per uno scalare
       






        double Coseno(const VettoreLineare &) const;
	VettoreLineare Versore();

};

#endif
