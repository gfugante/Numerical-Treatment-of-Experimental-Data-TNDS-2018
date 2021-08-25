#ifndef random_hpp
#define random_hpp
#include "gaussiana.h"
class Random{
private:
    unsigned int _a;
    unsigned int _c;
    unsigned int _m;
    unsigned int _seed;

public:
    Random(unsigned int seed);
    Random(unsigned int a, unsigned int c, unsigned int m, unsigned int seed);
    void SetA(unsigned int a) {_a=a;}
    void SetC(unsigned int c) {_c=c;}
    void SetM(unsigned int m) {_m=m;}
    int GetA() {return _a;}
    int GetC() {return _c;}
    int GetM() {return _m;}
    void SetSeed(int s) {_seed=s;}
    double Rand();
	double ARGauss(Gaussiana *f);
	double BMGauss(Gaussiana *f);
    double TExp(double lambda);
};
#endif /* random_hpp */
