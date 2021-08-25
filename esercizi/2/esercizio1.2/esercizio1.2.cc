#include <iostream>
#include <fstream>
#include "prototipi.h"

using namespace std;

int main(){

	ifstream ingresso("data.txt");
	ofstream output("output.txt");

	int N;
	double a,b;
	ingresso>>N;
	double array[N];
	for(int i=0; i<N; i++){
		ingresso>>array[i];
	};
	for(int i=0; i<N; i++){
		scambiabyreference(array[i],array[i++]);
	};

	for(int i=0; i<N; i++){
		output<<array[i]<<endl;
	};

return 0;

}
