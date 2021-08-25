#include <iostream>
#include <cmath>
#include "posizione.h"

using namespace std;

posizione::posizione(){
	_x=0;
	_y=0;
	_z=0;
}

posizione::posizione(double x, double y, double z){
	_x=x;
	_y=y;
	_z=z;
}

posizione::~posizione(){
}

void posizione::setposizione(double x, double y, double z){
	_x=x;
	_y=y;
	_z=z;
}

double posizione::x() const{
	return _x;
}
double posizione::y() const{
	return _y;
}
double posizione::z() const{
	return _z;
}

double posizione::R() const{
	return sqrt(_x*_x+_y*_y+_z*_z);
}
double posizione::phi() const{
	return atan2(_y,_x);
}
double posizione::theta() const{
	return acos(_z/R());
}

double posizione::rho() const{
	return sqrt(_x*_x+_y*_y);
}
double posizione::distanza(const posizione & b) const{
	return sqrt(pow(x()-b.x(),2)+pow(y()-b.y(),2)+pow(z()-b.z(),2));
}

