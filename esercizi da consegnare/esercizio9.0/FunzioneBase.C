#include <cmath>
#include <algorithm>

#include "FunzioneBase.h"
#include "Random.h"


using namespace std;

double FunzioneBase::MaxRel (double a, double b, double eps)
{
	Random r(1);
	double y = r.Uniform(a, b);
	double x;
	double M = (a + b) / 2;

	double fmax = Eval(M);

	x = Eval(y);

	while (fabs(M - y) > eps)
	{
		if ( x >= fmax)
			M = y;
		
		y = r.Uniform(a, b);

		x = Eval(y);		
	}

	return M;
}
