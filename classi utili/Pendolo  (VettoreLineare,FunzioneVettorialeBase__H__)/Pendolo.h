#ifndef __Pendolo_h__
#define __Pendolo_h__

#include <cstdlib>
#include <cmath>
#include "VettoreLineare.h"
#include "FunzioneVettorialeBase.h"

class Pendolo: public FunzioneVettorialeBase 
{
	protected:
		double _l;
	
	public:
		Pendolo(double);
		
		~Pendolo();
		
		virtual VettoreLineare Eval(double, const VettoreLineare&) const;
};

#endif
