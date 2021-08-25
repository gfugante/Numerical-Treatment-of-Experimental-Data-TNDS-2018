#ifndef __RungeKutta_h__
#define __RungeKutta_h__

#include "VettoreLineare.h"
#include "FunzioneVettorialeBase.h"
#include "EquazioneDifferenziale.h"

class RungeKutta: public EquazioneDifferenzialeBase
{
	public:
		RungeKutta();
		~RungeKutta();

		virtual VettoreLineare Passo(double, const VettoreLineare&, double, FunzioneVettorialeBase *) const;
};

#endif
