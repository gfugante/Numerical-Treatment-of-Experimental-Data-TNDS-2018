#include <iostream>
#include <cmath>
#include "campovettoriale.h"
#include "particelle.h"
#include "posizione.h"
using namespace std;

campovettoriale::campovettoriale(const posizione & s):posizione(s.x(),s.y(),s.z()) {
	_fx=0;
	_fy=0;
	_fz=0;

}

campovettoriale::campovettoriale(double x, double y, double z, double fx, double fy, double fz):posizione(x,y,z){
	_fx=fx;
	_fy=fy;
	_fz=fz;
}

void campovettoriale::set_fx(double fx){
	_fx=fx;
	return;
}

void campovettoriale::set_fy(double fy){
	_fy=fy;
	return;
}

void campovettoriale::set_fz(double fz){
	_fz=fz;
	return;
}

double campovettoriale::get_fx() const{
	return _fx;
}

double campovettoriale::get_fy() const{
	return _fy;
}

double campovettoriale::get_fz() const{
	return _fz;
}

double campovettoriale::get_modulo() const{
	return sqrt(_fx*_fx+_fy*_fy+_fz*_fz);
}

void campovettoriale::get_somma(const campovettoriale & F){
	_fx=_fx+(F.get_fx());
	_fy=_fy+(F.get_fy());
	_fz=_fz+(F.get_fz());
}

campovettoriale::~campovettoriale() {}






