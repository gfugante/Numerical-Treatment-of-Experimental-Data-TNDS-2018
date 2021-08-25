#include <iostream>
#include <cmath>
#include <cstdlib>
#include "posizione.h"

using namespace std;

int main(int argc, char** argv){

	if(argc!=4){
		std::cerr<<"Usage: "<<argv[0]<<" <x> <y> <z> "<<endl;
		return -1;
	}
	double x=atof(argv[1]);
	double y=atof(argv[2]);
	double z=atof(argv[3]);

	posizione P(x,y,z);
	cout<<"coordinate cartesiane: "<<P.x()<<","<<P.y()<<","<<P.z()<<endl;
	cout<<"coordinate cilindriche: "<<P.rho()<<","<<P.phi()<<","<<P.z()<<endl;
	cout<<"coordinate sferiche: "<<P.R()<<","<<P.phi()<<","<<P.theta()<<endl;
	return 0;
}
