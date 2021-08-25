#include "Random.h"
#include <cmath>
#include <iostream>

Random::Random(int seed){
	_seed = seed;
	_a=1664525;
	_c=1013904223;
	_m=pow(2,31);
	_n0 = seed;
}


double Random::Rand(){
	
	int ni;
	double di;
	
	ni = (_a*_n0+_c)%_m;
	di = double(ni)/double(_m-1);
	_n0 = ni;

	return di;		
}
