#include "Posizione.h"
#include "CampoVettoriale.h"
#include <cmath>
#include <iomanip>
using namespace std;


CampoVettoriale::CampoVettoriale(double x, double y, double z){
	_Cx=0;
	_Cy=0;
	_Cz=0;
}

CampoVettoriale::CampoVettoriale(const Posizione& r){
	_Cx=0;
	_Cy=0;
	_Cz=0;
}

CampoVettoriale::~CampoVettoriale(){}


double CampoVettoriale::modulo () const{
	return sqrt(pow(_Cx,2) + pow(_Cy,2) + pow(_Cz,2));
}


void CampoVettoriale::somma(CampoVettoriale& campo2){
	_Cx=_Cz+campo2.Cx();
	_Cy=_Cz+campo2.Cy();
	_Cz=_Cz+campo2.Cz();
}

void CampoVettoriale::print() const{
	cout<<"Le compoenti del campo sono: "<<scientific<<setprecision(2)<<"("<<_Cx<<","<<_Cy<<","<<_Cz<<")"<<endl;
}
