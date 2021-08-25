#ifndef solutore_h
#define solutore_h
#include "funzionebase.h"
class Solutore{
public:
    virtual double Cercazeri()=0;
protected:
    double m_xmin, m_xmax, m_prec;
    FunzioneBase *f;
};

#endif /* solutore_h */
