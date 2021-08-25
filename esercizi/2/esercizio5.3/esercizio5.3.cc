#include <iostream>
#include <iomanip>
#include <cmath>
#include "funzioneBase.h"
#include "solutore.h"
#include "meccquant.h"
#include "bisezione.h"

using namespace std;

int main(){

	int cifre_significative=-log10(1E-6);
	funzioneBase * mq= new meccquant;
	bisezione bis;
	
	for(int n=1; n<=20; n++){
	cout<<fixed;
	cout<<n<<")"<<setprecision(cifre_significative)<<bis.cercaZeri(n*(M_PI), (n*(M_PI))+((M_PI)/2), 1E-6, mq)<<endl;
	}
	return 0;
}
