
#include <iostream>
#include <cmath>
#include "PuntoMateriale.h"
#include "Posizione.h"
#include "Particella.h"
#include "CampoVettoriale.h"


using namespace std;




PuntoMateriale::PuntoMateriale() : Posizione::Posizione(),Particella::Particella(){}

PuntoMateriale::~PuntoMateriale(){}

PuntoMateriale::PuntoMateriale(double x, double y, double z, double Massa, double Carica) : Posizione(x,y,z),Particella(Massa,Carica){}

PuntoMateriale::PuntoMateriale(Posizione& r, Particella& p) : Posizione(r),Particella(p){}

PuntoMateriale::PuntoMateriale(Posizione& r, double Massa, double Carica) : Posizione(r),Particella(Massa,Carica){}

PuntoMateriale::PuntoMateriale(double x, double y, double z, Particella& p) : Posizione(x,y,z),Particella(p){}
		


CampoVettoriale PuntoMateriale::campoElettrico(const Posizione& r){
	double d3 = pow(3,Distanza(r));
	double _X = (9E9*carica)*((r.X()-X())/d3);
	double _Y = (9E9*carica)*((r.Y()-Y())/d3);
	double _Z = (9E9*carica)*((r.Z()-Z())/d3);
	CampoVettoriale campo(r);
	campo.setCx(_X);
	campo.setCy(_Y);
	campo.setCz(_Z);
	return campo;
}

CampoVettoriale PuntoMateriale::campoGravitazionale(const Posizione& r){
	double d3 = pow(3,Distanza(r));
	double _X = (6.67E-11*massa)*((r.X()-X())/d3);
	double _Y = (6.67E-11*massa)*((r.Y()-Y())/d3);
	double _Z = (6.67E-11*massa)*((r.Z()-Z())/d3);
	CampoVettoriale campo(_X,_Y,_Z);
	return campo;
}
		
void PuntoMateriale::print() const{
	cout<<"Punto materiale:"<<endl;
	cout<<"massa = "<<massa<<endl;
	cout<<"carica = "<<carica<<endl;
	cout<<"posizione = "<<"("<<X()<<","<<Y()<<","<<Z()<<")"<<endl;
}
















