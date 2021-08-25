#ifndef __puntomat__
#define __puntomat__

#include <iostream>
#include "Posizione.h"
#include "Particella.h"
#include "CampoVettoriale.h"


using namespace std;



class PuntoMateriale : public Posizione, public Particella{

	public:
		PuntoMateriale();
		~PuntoMateriale();
		PuntoMateriale(double x, double y, double z, double Massa, double Carica);
		PuntoMateriale( Posizione&,  Particella&);
		PuntoMateriale( Posizione&, double, double);
		PuntoMateriale(double, double, double , Particella&);

		
		CampoVettoriale campoElettrico(const Posizione& r);
		CampoVettoriale campoGravitazionale(const Posizione& r);
		
		void print() const;

};

#endif
