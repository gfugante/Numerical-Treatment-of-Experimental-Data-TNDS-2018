#ifndef __VettoreDati_h__
#define __VettoreDati_h__

#include <fstream>

#include "Vettore.h"


using namespace std;

class VettoreDati: public Vettore
{
	private:
		Vettore *_vec;
		/*unsigned int _N;
		double *_v;*/

	public:
		VettoreDati(const char *filename);
		VettoreDati(unsigned int N, ifstream &in);
		~VettoreDati() {delete[] _v;};

		void print () const;
		void print (ofstream& out) const;

		void selectionSort ();
};

#endif
