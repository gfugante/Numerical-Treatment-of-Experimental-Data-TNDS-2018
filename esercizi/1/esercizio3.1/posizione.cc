#include "posizione.hh"
#include <cmath>

posizione::posizione(){
	m_r=0.;
	m_theta=0.;
	m_phi=0.;
}

posizione::posizione(double x, double y, double z){ //passo le cartesiane
	m_r=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	m_theta=acos(z/m_r);
	m_phi=atan2(y,x);
}

posizione::~posizione(){
}

double posizione::x() const{
	return m_r*cos(m_phi)*sin(m_theta);
}

double posizione::y() const{
	return  m_r*sin(m_phi)*sin(m_theta);
}

double posizione::z() const{
	return m_r*cos(m_theta);
}

double posizione::r() const{
	return m_r;
}

double posizione::phi() const{
	return m_phi;
}


double posizione::theta() const{
	return m_theta;
}

double posizione::rho() const{
	return sqrt(pow(x(),2)+pow(y(),2));
}

double posizione::distanza (const posizione& b) const{
	return sqrt(pow(x()-b.x(),2)+pow(y()-b.y(),2)+pow(z()-b.z(),2));
}


