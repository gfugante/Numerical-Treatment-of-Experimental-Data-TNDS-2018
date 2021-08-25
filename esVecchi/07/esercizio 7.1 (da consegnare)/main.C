#include <iostream>
#include <iomanip>
#include <cmath>
#include "FunzioneBase.h"
#include "Integrale.h"



using namespace std;


int main(){

	cout<<"La seguente tabella riporta la precisione raggiunta relativa al numero di passi"<<endl;
	cout<<"n passi"<<setw(20)<<"precisione"<<endl;
	double a=0.;
	double b=M_PI;	
	int w = 22;


	FunzioneBase* seno = new Seno();
	Integral* integrale = new Integral(a,b,seno);

	for(int i=1; i<20; i++){
		int nstep = i*500;
		
		cout<<setprecision(2)<<nstep<<setw(w)<<scientific<<abs(2-integrale->midpoint(nstep))<<endl;
		w = 21;
	}

	return 0;
}
