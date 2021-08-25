#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double data[4]={4,7,13,16};
	double sum=0;
	double sum2=0;
	for(int i=0;i<4;i++){
		sum=sum+data[i];
		}
	double med;
	med=sum/4;
	cout<<"<x>="<<med<<endl;
	for(int j=0;j<4;j++){
		sum2=sum2+pow(data[j],2);
		}
	double med2;
	med2=sum2/4;
	cout<<"Varianza="<<(4/3)*(med2-pow(med,2))<<endl;

	double data_hugenumber[4]={4+1E9,7+1E9,13+1E9,16+1E9};
	double sum3=0;
	double sum4=0;
	for(int i=0;i<4;i++){
		sum3=sum3+data_hugenumber[i];
		}
	double med3;
	med3=sum3/4;
	cout<<"<x_2>="<<med3<<endl;
	for(int j=0;j<4;j++){
		sum4=sum4+pow(data_hugenumber[j],2);
		}
	double med4;
	med4=sum4/4;
	cout<<"Varianza_2="<<(4/3)*(med4-pow(med3,2))<<endl;
	
	return 0;
	}
		
