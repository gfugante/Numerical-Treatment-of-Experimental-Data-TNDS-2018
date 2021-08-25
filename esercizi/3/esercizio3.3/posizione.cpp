#include "posizione.hpp"
#include <cmath>

Posizione::Posizione()
{
    m_X=0;
	m_Y=0;
	m_Z=0;
}

Posizione::Posizione(double x, double y, double z)
{
    m_X=x;
	m_Y=y;
	m_Z=z;
}

Posizione::~Posizione() {}

double Posizione::Distanza(const Posizione& b) const
{
	return sqrt( pow(X()-b.X(),2)+pow(Y()-b.Y(),2)+pow(Z()-b.Z(),2));
}
