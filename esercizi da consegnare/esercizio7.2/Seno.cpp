#include <cmath>

#include "FunzioneBase.h"
#include "Seno.h"


using namespace std;

Seno::Seno( double alpha)
{
	_alpha = alpha;
}

Seno::Seno()
{
	_alpha = 0;
}

double Seno::Eval(double x) const
{
	return sin(x);
}
