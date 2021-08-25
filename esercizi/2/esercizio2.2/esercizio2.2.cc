#include <iostream>
#include <cstdlib>
#include <fstream>
#include "vettore.h"

using namespace std;

struct vettore{
	unsigned int N;
	double* v;
};

int main(int argc, char** argv){
	if(argc<3){
		cerr<<"uso:"<<argv[0]<<"<N_points> <filename>"<<endl;
		return -1;
	}

	unsigned int N=atoi(argv[1]);
	struct vettore vec=read(N, argv[2]);
	stampa1(vec);
	selection_sort(vec);
	stampa2(vec);
	delete[] vec.v;
	return 0;
}

	
