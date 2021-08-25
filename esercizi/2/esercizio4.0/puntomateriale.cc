#include <iostream>
#include <cmath>
#include "puntomateriale.h"
#include "particelle.h"
#include "posizione.h"
#include "campovettoriale.h"

using namespace std;

puntomateriale::puntomateriale(double x, double y, double z, double massa, double carica): posizione(x,y,z), particelle(massa, carica){
}

double puntomateriale::get_x(){
	return _x;
}

double puntomateriale::get_y(){
	return _y;
}

double puntomateriale::get_z(){
	return _z;
}

double puntomateriale::get_carica(){
	return _carica;
}

double puntomateriale::get_massa(){
	return _massa;
}

campovettoriale puntomateriale::get_campo_elettrico(const posizione & r) const{
	double a=1/(4*3.14*8.85E-12)*(_carica)*abs(r.x()-_x)/(pow(abs(r.x()-_x),2)+pow(abs(r.y()-_y),2)+pow(abs(r.z()-_z),2));
	double b=1/(4*3.14*8.85E-12)*(_carica)*abs(r.y()-_y)/(pow(abs(r.x()-_x),2)+pow(abs(r.y()-_y),2)+pow(abs(r.z()-_z),2));
	double c=1/(4*3.14*8.85E-12)*(_carica)*abs(r.z()-_z)/(pow(abs(r.x()-_x),2)+pow(abs(r.y()-_y),2)+pow(abs(r.z()-_z),2));
	return campovettoriale(r.x(), r.y(), r.z(), a, b, c);
}

campovettoriale puntomateriale::get_campo_gravitazionale(const posizione & r) const{
	double a=6.67E-11*(_massa)*abs(r.x()-_x)/(pow(abs(r.x()-_x),2)+pow(abs(r.y()-_y),2)+pow(abs(r.z()-_z),2));
	double b=6.67E-11*(_massa)*abs(r.y()-_y)/(pow(abs(r.x()-_x),2)+pow(abs(r.y()-_y),2)+pow(abs(r.z()-_z),2));
	double c=6.67E-11*(_massa)*abs(r.z()-_z)/(pow(abs(r.x()-_x),2)+pow(abs(r.y()-_y),2)+pow(abs(r.z()-_z),2));
	return campovettoriale(r.x(), r.y(), r.z(), a, b, c);
}

puntomateriale::~puntomateriale() {}
