#include <iostream>
#include "Posizione.h"
#ifndef __campo__
#define __campo__

class CampoVettoriale : public Posizione{

	protected: 
		double _Cx;
		double _Cy;
		double _Cz;
	
	public:
		CampoVettoriale(const Posizione& r);
		CampoVettoriale (double ,double ,double );	
		~CampoVettoriale();


		double Cx(){return _Cx;};
		double Cy(){return _Cy;};
		double Cz(){return _Cz;};

		void setCx(double d){_Cx=d;};
		void setCy(double d){_Cy=d;};
		void setCz(double d){_Cz=d;};


		double modulo () const;
		void somma(CampoVettoriale&);
		void print() const;
};

#endif 

