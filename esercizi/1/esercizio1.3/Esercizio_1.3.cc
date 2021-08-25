#include <iostream>
#include <cmath>
#include <iomanip>
#include "funzioni.hh"

using namespace std;



int main (){
	cout<<"1)"<<endl;
	cout<<endl; 
	float a,b,c,d,e,f;	
    	a=0.3 - 0.2 - 0.1;	
    	b=0.3 - (0.2 + 0.1);
    	c=0.4 - 0.3 - 0.1;
    	d=0.4 - (0.3 + 0.1);
    	e=(1E15+ 1) - 1E15;
    	f=(1E16 + 1) - 1E16;
	cout<<scientific<<setprecision(4)<<"a= "<<a<<" b="<<b<<" c="<<c<<" d="<<d<<" e="<<e<<" f="<<f<<endl;
	cout<<endl;

	cout<<"2)"<<endl;
	cout<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"x"<<setw(32)<<"fconerrore(x)"<<setw(19)<<"fmigliore(x)"<<endl; 
	cout<<"-------------------------------------------------------"<<endl;
	cout<<endl;
	double h,g,l;
	l=1;
	for(int i=0;i<=18;i++){
		g=sqrt(l+1)-sqrt(l);
		h=1/(sqrt(l+1)+sqrt(l));//razionalizzazione della funzione
		cout<<scientific<<l<<setw(20)<<g<<setw(20)<<h<<endl;
		l=l*10;
		}

	
 	cout<<endl;
	cout<<"3)"<<endl;
	cout<<endl;
	double data[4]={4, 7, 13, 16,};
	int n;
	n=4;
	double med, var;
	med = media(data, n);
	var = varianza (data, n);  
	cout<<"La media dell' array data e': "<<med<<endl;
	cout<<"La varianza dell' array data e': "<<var<<endl;
	cout<<endl;
	double var2,med2;
	double data_hugenumber[4];
	for (int i=0; i<n; i++){
		data_hugenumber[i]=data[i]+1E9;
		}
	med2 = media(data_hugenumber, n);
	var2 = varianza(data_hugenumber, n);
	cout<<"La media dell' array data_hugenumber e': "<<med2<<endl;
	cout<<"La varianza dell' array data_hugenumber e': "<<var2<<endl;
	//la varianza non è la stessa anche se si è traslato tutto di una costante perchè si lavora con grandi numeri
	cout<<endl;

	cout<<"4)"<<endl;
	cout<<endl;
	double m,o;
	o=1;
	for(int i=0;;i++){
		m=(o+1)-o;
		if(m!=1){
			cout<<"Il primo esponente per cui si ha un risultato sbagliato è "<<i<<endl;
		break;
			}
		o=o*10;
		}

		cout<<endl;
		return 0;
}
