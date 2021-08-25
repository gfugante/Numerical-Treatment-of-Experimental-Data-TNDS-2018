#include "Posizione.h"
#include <cmath>
using namespace std;


Posizione::Posizione(){
	_x=0;
	_y=0;
	_z=0;
}

Posizione::Posizione(double x, double y, double z){
	_x=x;
	_y=y;
	_z=z;
}

Posizione::~Posizione(){};

double Posizione::X() const{
	return _x;}
	
double Posizione::Y() const{
	return _y;}
	
double Posizione::Z() const{
	return _z;}
	
double Posizione::R() const{
	return sqrt(_x*_x+_y*_y+_z*_z);}
	
double Posizione::Phi() const{
	return atan2(_y,_x);}
	
double Posizione::Theta() const{
	return acos(_z/R());}
	
double Posizione::Rho() const{
	return sqrt(_x*_x+_y*_y);}
	
	
		
double Posizione::Distanza(const Posizione& b)const{
	return sqrt(pow(X()-b.X(),2) + pow(Y()-b.Y(),2) + pow(Z()-b.Z(),2));
}
		
		
		
		
