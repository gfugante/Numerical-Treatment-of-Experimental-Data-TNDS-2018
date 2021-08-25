#include <iostream>
#include <cstdlib>
#include "Posizione.h"
#include "PuntoMateriale.h"
#include "CampoVettoriale.h"

using namespace std;

int main (int argc, char** argv){
	if(argc!=4){
		cout<<"Usage: "<<argv[0]<<" <x> <y> <z> "<<endl;
		return -1;
	}
	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double z = atof(argv[3]);
	Posizione r(x,y,z);
	
	
	const double e = 1.60217653E-19;
	const double me = 9.1093826E-31;
	const double mp = 1.67262171E-27;
	const double d = 1.E-10;

	PuntoMateriale elettrone(0,0,d/2,me,-e);
	PuntoMateriale protone(0,0,-d/2,mp,e);

	
	CampoVettoriale E(r);
	CampoVettoriale *tmp = new CampoVettoriale(r);
	*tmp = elettrone.campoElettrico(r);
	E.somma(*tmp);
	*tmp = protone.campoElettrico(r);
	E.somma(*tmp);
	E.print();

	return 0;
}
