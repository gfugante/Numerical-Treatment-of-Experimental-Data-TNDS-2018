#ifndef __char_h__
#define __char_h__

#include  "FunzioneBase.h"

class SferaChar : public FunzioneBase
{
	private:
		double _r;
	public:
		SferaChar(double );
		virtual double Eval (double x) const;
};

#endif
