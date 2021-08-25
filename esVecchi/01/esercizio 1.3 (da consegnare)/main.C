#include <iostream>
#include <iomanip>
#include <cmath>
#include "statistica.h"

using namespace std;

int main(){

//1
	cout<<"1)"<<endl;
	cout<<"0.3-0.2-0.1 = "<<scientific<<0.3-0.2-0.1<<endl;
	cout<<"0.3-(0.2+0.1) = "<<scientific<<0.3-(0.2+0.1)<<endl;
	cout<<"0.4-0.3-0.1 = "<<scientific<<0.4-0.3-0.1<<endl;
	cout<<"0.4-(0.3+0.1) = "<<scientific<<0.4-(0.3+0.1)<<endl;
	cout<<"0.3-0.2-0.1 = "<<scientific<<0.3-0.2-0.1<<endl;
	cout<<"(1E15+1)-1E15 = "<<scientific<<(1E15+1)-1E15<<endl;
	cout<<"(1E16+1)-1E16 = "<<scientific<<(1E16+1)-1E16<<endl;
	cout<<endl;

//2
	cout<<"2)"<<endl;
	cout<<"x"<<setw(10)<<"fconerrore(x)"<<setw(10)<<"fmigliore(x)"<<endl;
	int x =1;
	for (int i=0; i<19; i++){
	double y = sqrt(x+1) + (((int(9.999999999999999999*x)-sqrt(x))+1)-(x*1E1));
		cout<<i<<setw(15)<<scientific<<setprecision(4)<<sqrt(x+1)-sqrt(x)<<setw(15)<<setprecision(4)<<scientific<<y<<endl;
		x=x*1E1;
	}

//3
	cout<<endl;
	cout<<"3)"<<endl;
	int n = 4;
	double data[4] = {4, 7, 13, 16};

	cout<<"V = ";
	for(int j=0; j<n; j++){
		cout<<fixed<<data[j]<<setw(6);
	}
	cout<<endl;

	cout<<"La media sul vettore V è: "<<mediaAritmetica(data,n)<<endl;	
	cout<<"La varianza sul vettore V è: "<<varianza(data,n)<<endl;	
	
	double data_hugenumber[4];

	for (int j=0; j<n; j++){
		data_hugenumber[j] = data[j]+1E9;
	}

	cout<<"La varianza sul vettore incrementato di 10^9 è: "<<varianza(data_hugenumber,n)<<endl;
	return 0;
}


