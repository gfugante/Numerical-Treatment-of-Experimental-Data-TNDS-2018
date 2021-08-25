#include <iostream>
#ifndef __posizione_h__
#define __posizione_h__

class Posizione{
	
	public:
	Posizione();
	Posizione (double x, double y, double z);
	~Posizione();

	double X () const;
	double Y () const;
	double Z () const;
	double R () const;
	double Phi () const;
	double Theta () const;
	double Rho () const;
	double Distanza (const Posizione&) const;
	
	private:
	double _x, _y, _z;
};

#endif 
