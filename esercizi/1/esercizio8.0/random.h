#ifndef _Random_h
#define _Random_h



#include<cmath>
class Random{
	public:
	  Random (int seed){ _seed=seed; _a=1664525; _c=1013904223; _m=pow(2, 31);}
	~Random(){ ;}
	void setA(int a){_a=a;}
	void setC(int c){_c=c;}
	void setM(int m){_m=m;}
	void setSeed(int seed){_seed=seed;}
	double Rand();	
	private:
	unsigned int _a;
	unsigned int _c;
	unsigned int _m;
	unsigned int _seed;
};
#endif

