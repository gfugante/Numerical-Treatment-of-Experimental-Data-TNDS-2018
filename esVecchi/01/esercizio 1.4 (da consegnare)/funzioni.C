#include <cmath>


double modulo(double a){
	return pow(sqrt(a),2.0);
}


double modulo(double a, double b){
	double a2 = pow(a,2.0);	
	double b2 = pow(b,2.0);
	return sqrt(a2+b2);
}


double modulo(double v[],int n){
	int somma = 0;	
	for(int i=0; i<n; i++){
		somma += v[i];
	}
	return sqrt(somma);
}

