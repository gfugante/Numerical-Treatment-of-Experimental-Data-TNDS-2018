#include <iostream>
#include <cstdlib>
#include "posizione.h"
#include "puntomateriale.h"
#include "campovettoriale.h"

using namespace std;

int main(int argc, char** argv){
	if(argc!=4){
		std::cerr<<"Usage: "<<argv[0]<<"<x> <y> <z>"<<endl;
		exit(-1);
	}

	double x=atof(argv[1]);
	double y=atof(argv[2]);
	double z=atof(argv[3]);
	posizione r(x,y,z);

	const double e=1.60217653E-19;
	const double me=9.1093826E-31;
	const double mp=1.67262171E-27;
	const double d=1.E-10;

	puntomateriale elettrone(0., 0., d/2., me, -e);
	puntomateriale protone(0., 0., -d/2.,mp, e);

	campovettoriale E(r);
	E.somma(elettrone.campoelettrico(r));
	E.somma(protone.campoelettrico(r));
	cout<<"E=("<<E.getvx()<<","<<E.getvy()<<","<<E.getvz()<<")"<<endl;

	return 0;
}
