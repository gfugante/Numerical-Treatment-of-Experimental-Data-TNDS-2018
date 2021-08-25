#ifndef __OscForzatoSmorzato_h__
#define __OscForzatoSmorzato_h__

#include <cstdlib>
#include <cmath>
#include "VettoreLineare.h"
#include "FunzioneVettorialeBase.h"

class OscForzatoSmorzato: public FunzioneVettorialeBase {
	protected:
		double _omega0;
		double _omegaf;
		double _alfa;
		
	public:
		OscForzatoSmorzato(double, double, double);
		
		~OscForzatoSmorzato();
		
		virtual VettoreLineare Eval(double, const VettoreLineare&) const;
};

#endif
