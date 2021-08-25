#include <math.h>
#include <cmath>
#include "particulartrigonometric.h"

F::F(int a){
    m_numzeros=a;
}

double F::Eval(double x) const{
     return sin(x)-x*cos(x);
}
