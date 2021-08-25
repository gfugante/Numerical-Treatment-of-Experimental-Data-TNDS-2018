#include "vettore.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct vettore read (unsigned int N, const char*filename){
	struct vettore v;
	v.N=N;
	v.v=new double [N];
	ifstream infile (filename);
	if(!infile){
		cerr<<"cannot open the file "<<filename<<endl;
	}else{
	for(unsigned int i=0;i<N;i++){
		infile>>v.v[i];
		if(infile.eof()){
			cerr<<"Stop reading after "<<i<<" entries"<<endl;
			break;
			}
		}
	}
	return v;
}

void print (const struct vettore vec){
	int width=static_cast <int> (log10(vec.N)+1);
	for(unsigned int i=0;i<vec.N; i++){
		cout<<setw(width)<<i+1<<" )"<<vec.v[i]<<endl;
		}
	return;
}

void print (const struct vettore vec, ofstream& outfile){
	int width=static_cast <int> (log10(vec.N)+1);
	for(unsigned int i=0;i<vec.N; i++){
		outfile<<setw(width)<<i+1<<" )"<<vec.v[i]<<endl;

		}
	return;
}

void selection_sort(struct vettore vett){ // ordina crescente

	for(int i=0; i<vett.N-1; i++){
		for(int j=i+1; j<vett.N; j++){

			if( vett.v[i]>vett.v[j]){
				scambia(&vett.v[i], &vett.v[j]);
			}
		}
	}
	return;
}



void scambia (double*a, double*b){
	double c;
	c=*a;
	*a=*b;
	*b=c;
	return;
}
	





























