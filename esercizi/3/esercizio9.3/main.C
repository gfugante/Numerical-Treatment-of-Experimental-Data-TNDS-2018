#include <iostream>
#include "Esperimentoprisma.h"
#include "random.hpp"
#include "math.h"
#include <cmath>
#include "vettore.h"
#include "vettoredati.h"
#include "integrale.hpp"

using namespace std;

int main(){
	double v[4],x;
	FunzioneBase *P;
	Integral H(-1,1,P);
	v[0]=H.MCMultiD(2,10000)/(pow(2,2));//rapport sn/rn
	v[1]=H.MCMultiD(3,10000)/(pow(2,3));
	v[2]=H.MCMultiD(4,10000)/(pow(2,4));
	v[3]=H.MCMultiD(5,10000)/(pow(2,5));
	cout<<"Rapporto volume sfera e cubo n dimensionale: "<<endl;
	for(int i=0; i<4; i++){
		cout<<"Dimensione "<<i+2<<":  "<<v[i]<<endl;
	}
	vettoreDati v1(1000), v2(1000), v3(1000), v4(1000);
    	for(int i=0; i<1000; i++){
        	x=H.MCMultiD(3,10000);
        	v1.setComponent(i,x);
        	x=H.MCMultiD(3,40000);
        	v2.setComponent(i,x);
        	x=H.MCMultiD(3,90000);
        	v3.setComponent(i,x);
        	x=H.MCMultiD(3,160000);
        	v4.setComponent(i,x);
    	}
    	v1.media();
    	v1.devSt();
    	v2.media();
   	v2.devSt();
   	v3.media();
    	v3.devSt();
    	v4.media();
    	v4.devSt();
	cout<<"Media e deviazione standard sul calcolo del volume di una sfera di raggio 1 a 3 dimensioni ad un numero di punti differente"<<endl;
	cout<<"Media e devst 10000: "<<v1.getMedia()<<"  "<<v1.getDevSt()<<endl;
	cout<<"Media e devst 40000: "<<v2.getMedia()<<"  "<<v2.getDevSt()<<endl;
	cout<<"Media e devst 90000: "<<v3.getMedia()<<"  "<<v3.getDevSt()<<endl;
	cout<<"Media e devst 160000: "<<v4.getMedia()<<"  "<<v4.getDevSt()<<endl;
	cout<<"Confronto valore volume della sfera ndimensionale con il valore atteso:"<<endl;
	cout<<"Dimensione 2: Valore calcolato  "<<H.MCMultiD(2,10000)<<"  Valore atteso   "<<M_PI/tgamma(2)<<endl;
	cout<<"Dimensione 3: Valore calcolato  "<<H.MCMultiD(3,10000)<<"  Valore atteso   "<<pow(M_PI,1.5)/tgamma(2.5)<<endl;
	cout<<"Dimensione 4: Valore calcolato  "<<H.MCMultiD(4,10000)<<"  Valore atteso   "<<pow(M_PI,2)/tgamma(3)<<endl;
	cout<<"Dimensione 5: Valore calcolato  "<<H.MCMultiD(5,10000)<<"  Valore atteso   "<<pow(M_PI,2.5)/tgamma(3.5)<<endl;
	
	return 0;
}
