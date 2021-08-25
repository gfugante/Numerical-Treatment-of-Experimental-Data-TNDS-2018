#ifndef gaussiana_hpp
#define gaussiana_hpp
#include "funzionebase.h"
class Gaussiana: public FunzioneBase{
public:	
	virtual double Eval(double x) const;
	Gaussiana(double mi, double sigma);
	void SetMi(double mi) {_mi=mi;}
	void SetSigma(double sigma) {_sigma=sigma;}
	double GetMi() {return _mi;}
	double GetSigma() {return _sigma;}
private:
	double _mi, _sigma;
};
#endif
