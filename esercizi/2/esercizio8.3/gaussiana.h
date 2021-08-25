#ifndef gaussiana_hpp
#define gaussiana_hpp
#include "funzioneBase.h"
class gaussiana: public funzioneBase{
public:	
	virtual double Eval(double x) const;
	gaussiana(double mi, double sigma);
	void SetMi(double mi) {_mi=mi;}
	void SetSigma(double sigma) {_sigma=sigma;}
	double GetMi() {return _mi;}
	double GetSigma() {return _sigma;}
private:
	double _mi, _sigma;
};
#endif
