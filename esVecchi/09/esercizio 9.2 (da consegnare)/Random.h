#ifndef RANDOM
#define RANDOM

#include "Gaussiana.h"


class Random{

public:
	Random(int seed);

	void setA(int a){_a=a;};
	void setC(int c){_c=c;};
	void setM(int m){_m=m;};

	double Rand();
	double Uniform(double a, double b);

	double AccRej(double a, double b, Gaussiana* f);
	double BoxMuller(double mean, double sigma);

	double Exponential(double lambda);
	
private:
	unsigned int _a; 
	unsigned int _c;
	unsigned int _m;
	unsigned int _seed;
};


#endif
