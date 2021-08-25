#ifndef _F_h
#define _F_h
#include "funzionebase.h"
class F: public FunzioneBase{
public:
    F(int a);
    virtual double Eval(double x) const;
private:
    int m_numzeros;
};
#endif
