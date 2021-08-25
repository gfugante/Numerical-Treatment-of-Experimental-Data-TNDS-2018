
#ifndef __punto__materiale__
#define __punto__materiale__

#include <iostream>


using namespace std;


class PuntoMateriale : public Posizione,Particella{

	public:
		PuntoMateriale();
		PuntoMateriale(double, double, double, double, double);
		~PuntoMateriale();

		CampoVettoriale CampoElettrico(const Posizione& r) const;
		CampoVettoriale CampoGravitazionale(const Posizione& r) const;


};


#endif

