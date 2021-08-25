#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

double modulo(double);
double modulo(double, double);
double modulo(double *,double);

int main(){
	double a,norma,norma2;
	cin>>a;
	a=modulo(a);
	cout<<a<<endl;

	double vett[2];
	for(int i=0; i<2; i++){
		cin>>vett[i];
	}
	norma=modulo(vett[0],vett[1]);
	cout<<norma<<endl;

	ifstream infile("data.txt");
	int n;
	infile>>n;
	double *v=new double[n];
	for(int i=0; i<n;i++){
		infile>>v[i];
		}
	norma2=modulo(v,n);
	cout<<norma2<<endl;

	return 0;
}

double modulo(double t ){
	if(t<0){
		t=-t;
	}
	return t;
}

double modulo(double a,double b){
	double norma;
	double s=0;
	s=pow(a,2)+pow(b,2);
	norma=sqrt(s);
	return norma;
}

double modulo(double *vettore,double n){
	double norma;
	double s=0;
	for(int i=0;i<n;i++){
		s=s+pow(vettore[i],2);
		}
	norma=sqrt(s);
	return norma;
}

