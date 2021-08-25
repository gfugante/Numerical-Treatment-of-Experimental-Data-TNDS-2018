#ifndef _SOLVER_H
#define _SOLVER_H_
#include "funzionebase.h"

class solutore{
	public:
		virtual double cercaZeri(double xmin, double xmax, const funzioneBase* f)=0;
		virtual double incertezza()=0;
		void setPrecision(double epsilon){ _prec=epsilon;}
		void setA(double a){_a=a;}
		void setB(double b){_b=b;}
		double getPrecision() const{return _prec;}
		double getA()const{return _a;}
		double getB() const {return _b;}
	protected:
		double _a,_b; //estremi della regione di ricerca
		double _prec; //precisione della soluzione
		double _incer; //incertezza finale
		const funzioneBase *_f; //funzione da passare per il calcolo
		
};

#endif
