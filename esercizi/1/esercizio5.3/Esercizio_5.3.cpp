//questo programma trova gli zeri della funzione periodica sinx-xcosx nei primi n=20 intervalli 
//con una precisione fissata nel main a priori (1E-6)

#include "funzionetan.h"
#include "bisezione.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define N 20

using namespace std;

int main(int argc, char**argv){ 

	const double prec=1E-6; //da cambiare se vogliamo prec diversa
	const int cifre_sig=-log10(prec); 
	double xmin=M_PI, xmax=M_PI+(M_PI)/2;
	xtan *f=new xtan;
	for(int n=1;n<=N;){
		bisezione b(prec, xmin, xmax);
		cout<<fixed
			<<setprecision(cifre_sig);
		cout<<"L'ascissa in cui la funzione sinx-xcosx si annulla con precisione assegnata nell'intervallo "
			<<n<<" e' "<<b.cercaZeri(b.getA(), b.getB(), f)<<endl;
		n++;
		xmin=M_PI*n; 
		xmax=n*M_PI+(M_PI)/2;
	}

	return 0;
}
	


