#ifndef RANDOM
#define RANDOM

#include "FunzioneBase.h"

class Random{

public:
	Random(int seed);
	void setA(int a){_a=a;};
	void setC(int c){_c=c;};
	void setM(int m){_m=m;};
	double Rand();
	double AccRej(double a, double b, Gaussiana* f);

	
private:
	unsigned int _a; 
	unsigned int _c;
	unsigned int _m;
	unsigned int _seed;
	unsigned int _n0;
};


#endif
