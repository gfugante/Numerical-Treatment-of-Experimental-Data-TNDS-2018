
#include <iostream>

using namespace std;


PuntoMateriale::PuntoMateriale() : Posizione(),Particella(){}

PuntoMateriale(double X, double Y, double Z, double Massa, double Carica) : Posizione(X,Y,Z),Particella(Massa,Carica){}

~PuntoMateriale(){}




CampoVettoriale CampoElettrico(const Posizione& r) const

CampoVettoriale CampoGravitazionale(const Posizione& r) const;
