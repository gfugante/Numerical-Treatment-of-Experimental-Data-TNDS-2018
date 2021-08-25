#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include "funzioneBase.h"
#include "seno.h"
#include "integrale.h"

using namespace std;

int main(int argc, const char ** argv){
	if(argc !=2){
		cout<<"Usage: npassi"<<endl;
		return -1;
	}

	double a=0.;
	double b= M_PI;
	double valvero=2.;
	int npassi=atoi(argv[1]);

	funzioneBase * sin = new seno();
	integrale * integral = new integrale(a, b, sin);
	cout<<"n interv "<<setw(22)<<"integrale "<<setw(22)<<"scarto "<<endl;
	for(int i=1; i<20; i++){
		double t=abs(valvero-integral->midpoint(i*npassi));
		cout<<setprecision(12)<<i*npassi<<setw(22)<<integral->midpoint(i*npassi)<<setw(22)<<t<<endl;
	}
	cout<<endl;
	cout<<"n interv "<<setw(22)<<"integrale "<<setw(22)<<"scarto "<<endl;
	for(int i=1; i<20; i++){
		double t=abs(valvero-integral->simpson(i*npassi));
		cout<<setprecision(12)<<i*npassi<<setw(22)<<integral->simpson(i*npassi)<<setw(22)<<t<<endl;
	}

	return 0;
}
	
