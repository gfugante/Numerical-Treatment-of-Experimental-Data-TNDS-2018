#ifndef __FunzioneVettorialeBase_h__
#define __FunzioneVettorialeBase_h__

#include "VettoreLineare.h"

class FunzioneVettorialeBase //classe astratta: i metodi non sono implementati
{
	public:
		virtual VettoreLineare Eval(double t, const VettoreLineare &x) const = 0;
};

#endif
