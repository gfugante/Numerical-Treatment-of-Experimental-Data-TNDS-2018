#include <iostream>
#include <cmath>
#include "puntomateriale.h"
#include "particelle.h"
#include "posizione.h"
#include "campovettoriale.h"

using namespace std;

const double eps0=8.854e-12;	
const double G=6.67e-11;

puntomateriale::puntomateriale(double x, double y, double z, double massa, double carica): posizione(x,y,z), particelle(massa, carica){
}

campovettoriale puntomateriale::campoelettrico(const posizione & r) const{
	double R=distanza(r);
	double k=getcarica()/(4.*M_PI*eps0*pow(R,3));
	double Ex=k*(r.x()-x());
	double Ey=k*(r.y()-y());
	double Ez=k*(r.z()-z());
	campovettoriale E(r,Ex,Ey,Ez);
	return E;
}

campovettoriale puntomateriale::campogravitazionale(const posizione &r) const{
	double R=distanza(r);
	double g=getmassa()*G/pow(R,3);
	double Gx=g*(r.x()-x());
	double Gy=g*(r.y()-y());
	double Gz=g*(r.z()-z());
	campovettoriale GR(r,Gx,Gy,Gz);
	return GR;
}
