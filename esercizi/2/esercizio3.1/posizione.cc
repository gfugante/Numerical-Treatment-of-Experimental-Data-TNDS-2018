#include <iostream>
#include <cmath>
#include "posizione.h"

using namespace std;

posizione::posizione(){
	_R=0;
	_phi=0;
	_theta=0;
}

posizione::posizione(double x, double y, double z){
	_R=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
	_theta=acos(z/(_R));
	_phi=asin(z/((_R)*sin(_theta)));
}

posizione::~posizione(){
}

double posizione::x() const{
	return _R*cos(_phi)*sin(_theta);
}
double posizione::y() const{
	return _R*sin(_phi)*sin(_theta);
}
double posizione::z() const{
	return _R*cos(_theta);
}

double posizione::R() const{
	return _R;
}
double posizione::phi() const{
	return _phi;
}
double posizione::theta() const{
	return _theta;
}

double posizione::rho() const{
	return (_R*cos(_phi)*sin(_theta))/(cos(_phi));
}
double posizione::distanza(const posizione& b) const{
	return sqrt(pow(x()-b.x(),2)+pow(y()-b.y(),2)+pow(z()-b.z(),2));
}

