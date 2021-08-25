#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "FunzioneBase.h"
#include "Integrale.h"



using namespace std;


int main(int argc, char **argv){

	if(argc!=2){
		cout<<"Usage: ese7.0 nstep"<<endl;
		return -1;
	}
	
double a=0.;
double b=2*M_PI;	
	
double nstep = atoi(argv[1]);

FunzioneBase* seno = new Seno();
Integral* integrale = new Integral(a,b,seno);
	
cout<<setprecision(12)<<integrale->midpoint(nstep)<<endl;
	
}
