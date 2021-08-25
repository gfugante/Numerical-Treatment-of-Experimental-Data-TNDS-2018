#ifndef _VETTORELINEARE_h_
#define _VETTORELINEARE_h_

#include "vettore.h"
#include <iostream>
using namespace std;

class vettoreLineare: public vettore{
	
	public:
	vettoreLineare(unsigned int n);
	//~vettoreLineare(){;}
	//algebra vettoriale 
	vettoreLineare operator+(const vettoreLineare&) const;
	double operator*(const vettoreLineare&) const;
	vettoreLineare operator*(const double) const;
	//manca l'angolo tra vettori
};
#endif 

