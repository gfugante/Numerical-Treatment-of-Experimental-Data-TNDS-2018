#include "random.h"

double Random::Rand(){ //mi restituisce un valore tra 0 e 1
	int n1, n0;
	n0=_seed;
	n1=(_a*n0+_c)%_m;
	setSeed(n1);
	return 1.*n1/(_m-1);
	}
