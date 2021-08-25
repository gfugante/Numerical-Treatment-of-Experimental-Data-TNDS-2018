#include <iostream>
#include"FunzioneBase.h"
#include "Solutore.h"
#include <iomanip>
#include <cmath>
using namespace std;

int main(){


	FunzioneBase *T = new XTanX();
		
	Bisezione *B = new Bisezione();
	B->setPrecision(1E-6);

	cout<<"Le soluzioni di x = tan(x) su intervalli del tipo(nπ,nπ+π/2) sono:"<<endl;
	cout<<"n	x"<<endl;


	for(int n=0; n<20; n++){
		cout<<n<<"	"<<fixed<<setprecision(2)<<B->CercaZeri(n*3.14,(n*3.14)+(3.14*0.5),T)<<endl;
	}

	return 0;
}



