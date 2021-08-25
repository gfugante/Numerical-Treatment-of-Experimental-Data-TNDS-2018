#ifndef _puntomateria_h
#define _puntomateriale_h

#include "posizione.hh"
#include "particella.hh"
#include "campovettoriale.hh"

class puntoMateriale: public posizione, particella{
	public:
	puntoMateriale();
	puntoMateriale(double m,double q,double x, double y, double z);
	~puntoMateriale();
	
	double moduloElettrico(const posizione& r)const;
	double moduloGravitazionale(const posizione& r)const;
	campoVettoriale campoElettrico(const posizione& r)const;
	campoVettoriale campoGravitazionale(const posizione& r)const;

	};

#endif
