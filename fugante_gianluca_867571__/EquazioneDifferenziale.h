#ifndef _equazioniDifferenziali_h_
#define _equazioniDifferenziali_h_

#include "VettoreLineare.h"
#include "FunzioneVettorialeBase.h"


class EquazioneDifferenzialeBase //classe astratta
{
	public:
		virtual VettoreLineare Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const = 0;
};

#endif
