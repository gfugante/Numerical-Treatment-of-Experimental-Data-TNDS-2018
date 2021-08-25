#include "parabola.h"
#include "funzionebase.h"
Parabola::Parabola()
{
    m_a=0;
    m_b=0;
    m_c=0;
}

Parabola::Parabola(double x, double y, double z)
{
    m_a=x;
    m_b=y;
    m_c=z;
}

double Parabola::Eval(double x) const
{
    return m_a*m_a*x+m_b*x+m_c;
}
