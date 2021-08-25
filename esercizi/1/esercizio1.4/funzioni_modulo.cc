#include "funzioni_modulo.hh"

double modulo (double num){
	double mod;
	if(num<0){mod=-num;
		return mod;}
	else{ return num;}
	}

double modulo (double a, double b){
	double mod;
	mod=sqrt(a*a+b*b);
	return mod;
	}

double modulo(double*vett, int n){
	double mod,sum2;
	sum2=0;
	for(int i=0;i<n; i++){
		sum2=vett[i]*vett[i]+sum2;
		}
	return mod=sqrt(sum2);
	}
	
