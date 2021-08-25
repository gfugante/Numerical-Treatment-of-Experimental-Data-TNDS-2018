#include <iostream>
#include "Posizione.h"
#include <cstdlib>

using namespace std;


int main(int argc, char **argv){

	if(argc!=4){
		cout<<"Inserire le coordinate <x> <y> <z>"<<endl;
		return -1;
	}

	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double z = atof(argv[3]);
	

	Posizione punto(x,y,z);

	cout<<"Le coordinate sferiche (R,Phi,Theta) sono: "<<endl;
	cout<<"("<<punto.R()<<","<<punto.Phi()<<","<<punto.Theta()<<")"<<endl;
	cout<<endl;
	

	cout<<"Le coordinate cartesiane (x,y,z) sono: "<<endl;
	cout<<"("<<punto.X()<<","<<punto.Y()<<","<<punto.Z()<<")"<<endl;
	cout<<endl;


	cout<<"Le coordinate cilindriche (R,Phi,Theta) sono: "<<endl;
	cout<<"("<<punto.Rho()<<","<<punto.Phi()<<","<<punto.Z()<<")"<<endl;
	cout<<endl;
	
	
	
	
	
}
