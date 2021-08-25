#ifndef bisezione_hpp
#define bisezione_hpp
#include "bisezione.hpp"
#include "solutore.h"
#include "funzionebase.h"
class Bisezione: public Solutore{
public:
    Bisezione(double a, double b, double eps, FunzioneBase *f);
    int Sign(double x);
    double Cercazeri();
    bool Check();
};
#endif /* bisezione_hpp */
