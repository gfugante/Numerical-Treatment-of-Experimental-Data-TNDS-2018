#ifndef __Cal_h__
#define __Cal_h__

#include <cstdlib>
#include <cmath>
#include "VettoreLineare.h"
#include "FunzioneVettorialeBase.h"

class Calorimetro: public FunzioneVettorialeBase 
{
	protected:
		double _T10,_T20,_K1,_K2;
		
	public:
		Calorimetro(double,double);
		~Calorimetro();
		void SetK(double K2){ _K2=K2; };
		virtual VettoreLineare Eval(double, const VettoreLineare&) const;
};


#endif
