#include "posizione.hh"
#include <cmath>

posizione::posizione(){
	m_x=0.;
	m_y=0.;
	m_z=0.;
}

posizione::posizione(double x, double y, double z){
	m_x=x;
	m_y=y;
	m_z=z;
}

posizione::~posizione(){
}

double posizione::x() const{
	return m_x;
}

double posizione::y() const{
	return m_y;
}

double posizione::z() const{
	return m_z;
}

double posizione::r() const{
	return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
}

double posizione::phi() const{
	return atan2(m_y,m_x);
}


double posizione::theta() const{
	return acos(m_z/r());
}

double posizione::rho() const{
	return sqrt(m_x*m_x+m_y*m_y);
}

double posizione::distanza (const posizione& b) const{
	return sqrt(pow(x()-b.x(),2)+pow(y()-b.y(),2)+pow(z()-b.z(),2));
}

void posizione::setX(double x){
	m_x=x;
	}

void posizione::setY(double y){
	m_y=y;
	}

void posizione::setZ(double z){
	m_z=z;
	}
