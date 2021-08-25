#include <cmath>

#include "SferaChar.h"


using namespace std;

SferaChar::SferaChar(double r)
{
	_r = r;
}

double SferaChar::Eval (double x) const
{
	if (abs(x) <= _r)
		return 1.;

	else
		return 0.;
}
