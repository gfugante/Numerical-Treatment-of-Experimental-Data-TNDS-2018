#include "posizione.hh"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char**argv){
	if (argc!=4){
		std::cerr<<"Usage: "<<argv[0]<< "<x> <y> <z> "<<endl;
		return -1;
	}
	double x=atof(argv[1]);
	double y=atof(argv[2]);
	double z=atof(argv[3]);

	posizione p (x,y,z);
	cout<<"coordinate cartesiane: (x,y,z)= ("<<p.x()<<","<<p.y()<<","<<p.z()<<")"<<endl;
	cout<<"coordinate cilindriche: (rho,theta,z)= ("<<p.rho()<<","<<p.phi()<<","<<p.z()<<")"<<endl;
	cout<<"coordinate sferiche: (rho,phi,theta)= ("<<p.r()<<","<<p.phi()<<","<<p.theta()<<")"<<endl;
	cout<<endl;
	return 0;
}
