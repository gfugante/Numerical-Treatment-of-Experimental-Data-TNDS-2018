#include <cmath>

//MEDIA

double mediaAritmetica(double data[], int n){
	double media=0;
	for(int j=0; j<n; j++){
		media += data[j];
	}
	media = media/n;
	return media;
}

//VARIANZA

double varianza(double data[],int n){
	double quadratoMedia = pow(mediaAritmetica(data,n),2.0);
	double *tmp = new double[n];
	for (int j=0; j<n; j++){
		tmp[j]=pow(data[j],2.0);
	}
	double mediaQuadrati = mediaAritmetica(tmp,n);
	delete []tmp;

	return ((mediaQuadrati-quadratoMedia)*n)/(n-1);

}


