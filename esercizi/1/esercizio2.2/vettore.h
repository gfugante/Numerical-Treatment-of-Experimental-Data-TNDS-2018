#ifndef _VETTORE_HH_
#define _VETTORE_HH_

#include <fstream>
using namespace std;

struct vettore {
	unsigned int N;
	double*v;
	};

vettore read (unsigned int, const char*);
void print (const struct vettore );
void print (const struct vettore, ofstream& outfile );
void selection_sort(struct vettore);
void scambia (double*a, double*b);

#endif

