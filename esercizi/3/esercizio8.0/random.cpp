#include "random.hpp"

Random::Random(unsigned int seed){
    _seed=seed;
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
