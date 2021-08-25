#include "funzioni.hh"

double media (double*vett, int n){
	double med;
	double sum=0;
	for (int i=0;i<n;i++){
		sum=vett[i]+sum;
		}
	med=sum/n;
	return med;
}

double varianza (double*vett, int n){
	double var,sum, sum2,med,med2;
	sum=0;
	sum2=0;
	for (int i=0; i<n ;i++){
		sum=sum+vett[i];
		sum2=vett[i]*vett[i]+sum2;
		}
	med=sum/n;
	med2=sum2/n;
	var=n/(n-1)*(med2-(med*med));
	return var;
	}

		
	
	
	
		
		
			
