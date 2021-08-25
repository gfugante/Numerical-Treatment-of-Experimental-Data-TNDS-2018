#include "posizione.hpp"
#include <cmath>

Posizione::Posizione()
{
    m_R=0.;
    m_Phi=0.;
    m_Theta=0.;
}

Posizione::Posizione(double x, double y, double z)
{
    m_R=sqrt(x*x+y*y+z*z);
    m_Phi=atan2(y,x);
    m_Theta=acos(z/(sqrt(x*x+y*y+z*z)));
}

Posizione::~Posizione() {}

double Posizione::X() const
{
    return m_R*cos(m_Phi)*sin(m_Theta);
}
double Posizione::Y() const
{
    return m_R*sin(m_Phi)*sin(m_Theta);
}
double Posizione::Z() const
{
    return m_R*cos(m_Theta);
}

double Posizione::R() const
{
    return m_R;
}
double Posizione::Phi() const
{
    return m_Phi;
}
double Posizione::Theta() const
{
    return m_Theta;
}

double Posizione::Rho() const
{
    return m_R*sin(m_Theta);
}

double Posizione::Distanza(const Posizione& b) const
{
    return sqrt( pow(X()-b.X(),2) +pow(Y()-b.Y(),2) +pow(Z()-b.Z(),2) );
}
