#ifndef _campovettoriale_h_
#define _campovettoriale_h_

#include "particelle.h"
#include "posizione.h"

class campovettoriale: public posizione{
	private:
		double _x,_y,_z;
		double _fx,_fy,_fz;
	public:
		campovettoriale(double x, double y, double z, double fx, double fy, double fz);
		campovettoriale(const posizione & s);
		void set_fx(double fx);
		void set_fy(double fy);
		void set_fz(double fz);

		double get_fx() const ;
		double get_fy() const;
		double get_fz() const;
		double get_modulo() const;
		void get_somma(const campovettoriale & F);
		~campovettoriale();
};

#endif
