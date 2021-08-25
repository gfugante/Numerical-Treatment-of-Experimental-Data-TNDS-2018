#ifndef __ATheta_h__
#define __ATheta_h__

#include "FunzioneBase.h"

class ATheta : public FunzioneBase
{
	private:
		double _r, _lambda, _theta;

	public:
		ATheta();
		~ATheta() {};
		
		double Eval(double t) const; 
		void SetR(double r) { _r = r;}
		void SetLambda(double lambda) { _lambda = lambda;}
		void SetTheta(double theta) { _theta = theta;}
		
		double GetR() {return _r;}
		double GetLambda() {return _lambda;}
		double GetTheta() {return _theta;}
};

#endif
