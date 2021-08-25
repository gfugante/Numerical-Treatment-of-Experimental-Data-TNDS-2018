#include "funzioni.hh"

int main(){

	int N=0;
	
	ifstream input("data.txt");
	ofstream output("output.txt");
	input>>N;
	
	cout<<"Numeri: "<<N<<endl;
	double*v=new double[N];
	
		
	for(int i=0; i<N; i++){
		input>>v[i];
	}
	
	for(int i=0;i<10;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	for(int i=0; i<N; i=i+2){
		scambia3(&v[i],&v[i+1]);
	}
	
	for(int i=0;i<10;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
		
	for(int i=0;i<N;i++){
		output<<v[i]<<endl;
	}
	
	return 0;
}
