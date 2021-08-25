#include "Random.h"
#include "Gaussiana.h"

#include <cmath>

using namespace std;

Random::Random(int seed)
{
	_seed = seed;
	_a = 1664525;
	_c = 1013904223;
	_m = pow(2,31);
}


double Random::Rand()
{
	
	int ni;
	double di;
	
	ni = (_a * _seed + _c) % _m;
	di = double(ni) / double(_m-1);
	_seed = ni;

	return di;		
}

double Random::Uniform(double a, double b)
{
	return a + Rand() * (b-a);
}

double Random::AccRej(double a, double b, Gaussiana* f)
{
	
	double x,y,s,t,max;
	max = f->Eval(f->GetMi());
	
	do{	
		double s = this -> Rand();
		double t = this -> Rand();
	
		x = a + (b-a) * s;
		y = max * t;
	}while(y >= f->Eval(x));
	
	return x;
	
}

double Random::BoxMuller(double mean, double sigma)
{
	double s = this -> Rand();
	double t = this -> Rand();
	double g = sqrt(-2. * log(s)) * cos(2. * M_PI * t);

	return mean + sigma * g;
}

double Random::Exponential(double lambda)
{
	return (-1. / lambda) * log(1. - Rand());
} 
