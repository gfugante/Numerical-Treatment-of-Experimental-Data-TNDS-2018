#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "funzioneBase.h"
#include "parabola.h"
#include "solutore.h"
#include "bisezione.h"

using namespace std;

int main(int argc, char** argv){
	if(argc!=4){
		std::cerr<<"Usage: "<<argv[0]<< "<a> <b> <prec>"<<endl;
		return -1;
	}

	double a=atof(argv[1]);
	double b=atof(argv[2]);
	double prec=atof(argv[3]);

	int cifre_significative=-log10(prec);

	funzioneBase * par= new parabola(3.,5.,-2.);
	bisezione bis;
	cout<<fixed;
	cout<<setprecision(cifre_significative)<<bis.cercaZeri(a, b, prec, par)<<endl;

	return 0;
}
