/* Questo programma calcola gli zeri della parabola assegnata 3x^2+5x-2 leggendo da riga di comando gli estremi dell'intervallo di ricerca e la precisione con cui si vuole tale zero (ce si cerca attraverso il metodo bisezione implementato come classe ocncreta derivante da quella astratta solutore), l'ascissa in cui la funzione si annulla viene stampate con la precisione riciesta */


#include "parabola.h"
#include "signfunction.h"
#include "bisezione.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char**argv){ 
	if(argc!=4){
		cerr<<" Usage: "<<argv[0]<<" <xmin> <xmax> <precision> "<<endl;
		return -1;
	}
	
	
	parabola *p=new parabola (3, 5, -2);
	double xmin, xmax, prec,xz; //xz è la x dello zero
	xmin=atof(argv[1]);
	xmax=atof(argv[2]);
	prec=atof(argv[3]);
	int cifre_sig=static_cast<int>(-log10(prec)); //setto la precisione che è pari ai decimali della prec
	bisezione b(prec, xmin, xmax);
	cout<<fixed; //
	xz=b.cercaZeri(b.getA(), b.getB(), p);
	cout<<cifre_sig<<endl;
	cout<<-log10(prec)<<endl;
	cout<<setprecision(cifre_sig); //stampo con la precisione
	if(b.getBoolean()){
	cout<<"La x in cui si annulla a precisione richiesta e' "<<xz<<endl;}
	b.setFalse();
	
	return 0;
}
	


