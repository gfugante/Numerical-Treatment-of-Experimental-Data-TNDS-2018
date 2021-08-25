#ifndef _puntomateriale_h_
#define _puntomateriale_h_

#include "particelle.h"
#include "posizione.h"
#include "campovettoriale.h"

class puntomateriale: public particelle, posizione {
	public:
		puntomateriale(double x, double y, double z, double massa, double carica);
		campovettoriale campoelettrico(const posizione & r) const;
		campovettoriale campogravitazionale(const posizione & r) const;
};

#endif
