
#ifndef __solutore__
#define __solutore__


#include "FunzioneBase.h"

class Solutore{

	protected:
		double _a,_b_,_prec;
		FunzioneBase *_f;

	public:
		Solutore();
		~Solutore();
		virtual double CercaZeri(double xmin, double xmax, const FunzioneBase *f)=0;
		void setPrecision(double epsilon){_prec = epsilon;};
		double getPrecision() const{return _prec;};
	
};


class Bisezione : public Solutore{
	
	protected:	
		int _interazioni;
		
	public:
		Bisezione();
		~Bisezione();
		virtual double CercaZeri(double xmin, double xmax, const FunzioneBase *f);
		double getInterazioni() const{return _interazioni;};
		void setInterazioni(int i){_interazioni=i;};
};

#endif
