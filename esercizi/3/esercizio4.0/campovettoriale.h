#ifndef _campovettoriale_h_
#define _campovettoriale_h_

#include "particelle.h"
#include "posizione.h"

class campovettoriale: public posizione{
	private:
		double m_v[3];
	public:
		campovettoriale(const posizione &a);
		campovettoriale(const posizione &a,double x, double y, double z);
		void set_vx(double vx){m_v[0]=vx;}
		void set_vy(double vy){m_v[1]=vy;}
		void set_vz(double vz){m_v[2]=vz;}
		double getvx() const {return m_v[0];}
		double getvy() const {return m_v[1];}
		double getvz() const {return m_v[2];}
		double modulo() const;
		void somma(const campovettoriale & F);
};

#endif
