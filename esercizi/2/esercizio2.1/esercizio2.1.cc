#include <iostream>
#include <fstream>
#include "prototipi.h"

using namespace std;

int main(){

	ifstream ingresso("data.txt");
	
	double a;
	double array[20];
	for(int i=0; i<20;i++){

		ingresso>>array[i];
	};
	
	for(int i=0;i<20;i++){
		scambiabyvalue(array[i], array[i++]);
	};
	for(int i=0;i<20;i++){
		cout<<array[i]<<" ";
	};
	cout<<endl;

	for(int i=0;i<20;i++){
		scambiabypointer(&array[i], &array[i++]);
	};
	for(int i=0;i<20;i++){
		cout<<array[i]<<" ";
	};
	cout<<endl;

	for(int i=0;i<20;i++){
		scambiabyreference(array[i],array[i++]);
	};
	for(int i=0;i<20;i++){
		cout<<array[i]<<" ";
	};
	cout<<endl;
	a=numeroscambi();

	cout<<"numero totale di scambi:"<<a<<endl;
return 0;
}
