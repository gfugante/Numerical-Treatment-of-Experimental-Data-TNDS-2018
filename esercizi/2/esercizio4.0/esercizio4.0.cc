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

	puntomateriale elettrone(me, -e, 0., 0., d/2.);
	puntomateriale protone(mp, e, 0., 0., -d/2.);

	campovettoriale E(r);
	E.get_somma(elettrone.get_campo_elettrico(r));
	E.get_somma(protone.get_campo_elettrico(r));
	cout<<"E=("<<E.get_fx()<<","<<E.get_fy()<<","<<E.get_fz()<<")"<<endl;

	return 0;
}
