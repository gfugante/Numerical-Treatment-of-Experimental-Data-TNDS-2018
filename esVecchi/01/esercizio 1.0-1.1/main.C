#include <iostream>
#include <iomanip>
#include "scambia.h"

using namespace std;



int main(){
	int a,b;
	cout<<"inserire il primo numero"<<endl;
	cin>>a;
	cout<<"inserire il secondo numero"<<endl;
	cin>>b;
	scambia(&a,&b);
	cout<<"Magia!"<<endl;
	cout<<a<<setw(4)<<b<<endl;
			
}



	

