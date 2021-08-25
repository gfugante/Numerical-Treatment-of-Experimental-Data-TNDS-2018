#ifndef __Gauss_h__
#define __Gauss_h__

#include "FunzioneBase.h"


class Gaussiana : public FunzioneBase
{
	private:
		double _mi, _sigma;

	public:
		Gaussiana();
		Gaussiana(double mi, double sigma);
		~Gaussiana() { };

		void SetMi(double mi) {_mi = mi;};
		void SetSigma(double sigma) {_sigma = sigma;};

		double GetMi() const {return _mi;};
		double GetSigma() {return _sigma;}; 

		double Eval(double x) const;
};

#endif
