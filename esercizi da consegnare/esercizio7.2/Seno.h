#ifndef __Seno_h__
#define __Seno_h__

#include "FunzioneBase.h"


class Seno : public FunzioneBase{

private:
	double _alpha;	//in radianti

public:
	Seno();
	Seno(double alpha);
		
	~Seno() { };

	virtual double Eval(double x) const;
	
	
	void setAlpha (double A){_alpha = A;};
	double getA(){return _alpha;};
	
	/*void setOmega(double omega){_omega = omega;};
	double getOmega(){return _omega;};

	void setPhi(double phi){_phi = phi;};
	double getPhi(){return _phi;};*/
	
};

#endif
