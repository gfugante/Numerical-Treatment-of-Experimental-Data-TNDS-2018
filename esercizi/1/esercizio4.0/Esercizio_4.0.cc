//Questo programma prende da riga di comando le coordinate cartesiane di un punto e stampa il valore del campo elettrico di dipolo prodotto da un un elettrone ed un protone posizionati ad una distanza di 10-10 m

#include "puntomateriale.hh"
#include "campovettoriale.hh"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char**argv) {
	if (argc!=4){
		cerr<<"Usage: "<<argv[0]<<" <x> <y> <z>"<<endl;
		exit(-1); 
		}	
	double x=atof(argv[1]);
	double y=atof(argv[2]);
	double z=atof(argv[3]);
	posizione r (x,y,z);

	const double e=1.60217653E-19;
	const double me=9.1093826E-31;
	const double mp=1.67262171E-27;
	const double d=1E-10;
	

	puntoMateriale elettrone (me, -e, 0, 0, d/2);
	puntoMateriale protone (mp, e, 0, 0, -d/2);
	
	cout<<endl;
	cout<<"Campo elettrico generato dall'elettrone"<<endl;
	campoVettoriale E(r);
	E.somma(elettrone.campoElettrico(r));
	cout <<"E=("<<E.getFx()<<", "<<E.getFy()<<", "<<E.getFz()<< ")"<<" N/C"<<endl<<endl;

	cout<<"Campo elettrico generato dal protone"<<endl;
	campoVettoriale P(r);
	P.somma(protone.campoElettrico(r));
	cout <<"E=("<<P.getFx()<<", "<<P.getFy()<<", "<<P.getFz()<< ")"<<" N/C"<<endl<<endl;

	cout<<"Campo elettrico generato dal dipolo"<<endl;
	E.somma(protone.campoElettrico(r));
	cout <<"E=("<<E.getFx()<<", "<<E.getFy()<<", "<<E.getFz()<< ")"<<" N/C"<<endl<<endl;

	cout<<"Campo gravitazionale generato dall'elettrone"<<endl;
	campoVettoriale G(r);
	G.somma(elettrone.campoGravitazionale(r));
	cout <<"G=("<<G.getFx()<<", "<<G.getFy()<<", "<<G.getFz()<< ")"<<" N/kg"<<endl<<endl;

	cout<<"Campo gravitazionale generato dal protone"<<endl;
	campoVettoriale G1(r);
	G1.somma(protone.campoGravitazionale(r));
	cout <<"G=("<<G1.getFx()<<", "<<G1.getFy()<<", "<<G1.getFz()<< ")"<<" N/kg"<<endl<<endl;

	cout<<"Campo gravitazionale generato dal dipolo"<<endl;
	G.somma(protone.campoGravitazionale(r));
	cout <<"G=("<<G.getFx()<<", "<<G.getFy()<<", "<<G.getFz()<< ")"<<" N/kg"<<endl<<endl;

		
	return 0;
}
