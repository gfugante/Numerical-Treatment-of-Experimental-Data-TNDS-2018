#include "random.hpp"
#include <cmath>

Random::Random(){
    _a=1664525;
    _c=1013904223;
    _m=pow(2,31);
    _seed=32;
}

double Random::Rand(){
    int rand=((_a*_seed+_c)%_m);
    _seed=rand;
    return (1.*rand)/(_m-1);
}

Random::Random(unsigned int a, unsigned int c, unsigned int m, unsigned int seed){
    _a=a;
    _c=c;
    _m=m;
    _seed=seed;
}
