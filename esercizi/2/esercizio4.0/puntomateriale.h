#ifndef _puntomateriale_h_
#define _puntomateriale_h_

#include "particelle.h"
#include "posizione.h"
#include "campovettoriale.h"

class puntomateriale: public particelle, posizione {
	private:
		double _x,_y,_z, _massa, _carica;
	public:
		puntomateriale(double x, double y, double z, double massa, double carica);
		double get_x();
		double get_y();
		double get_z();
		double get_carica();
		double get_massa();
		campovettoriale get_campo_elettrico(const posizione & r) const;
		campovettoriale get_campo_gravitazionale(const posizione & r) const;
		~puntomateriale();
};

#endif
