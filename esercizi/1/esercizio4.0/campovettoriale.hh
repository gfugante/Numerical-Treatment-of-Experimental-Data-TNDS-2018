#ifndef _campovettoriale_h
#define _campovettoriale_h

#include "posizione.hh"
#include <string>

class campoVettoriale:public posizione {
	public:
	campoVettoriale(const  posizione&);
	campoVettoriale();
	~campoVettoriale();

	double getFx() const {return _F[0];};
	double getFy() const {return _F[1];};
	double getFz() const {return _F[2];};
	void setFx (double fx) {_F[0]=fx;}; 
	void setFy (double fy) {_F[1]=fy;}; 
	void setFz (double fz) {_F[2]=fz;}; 

	double modulo() const;
	void somma (const campoVettoriale&);
	

	protected:
	posizione _p; 
	double _F[3]; //in F[0] mettiamo la componente x, in F[1] la y e in F[2] la z
	};
#endif

