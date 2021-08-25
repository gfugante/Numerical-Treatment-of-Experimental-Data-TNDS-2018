#ifndef _vettoredati_h_
#define _vettoredati_h_
#include <string>
#include "vettore.h"
#include <iostream>
using namespace std;

class Vettoredati: public Vettore {

	public:
		Vettoredati(unsigned int N);	
		Vettoredati(unsigned int N, const char* Namefile);
		void Print(int N);
		void Print(int N, const char* Namefile);
		void Ordina();
		double Media();
		double Sigma();
		
};
#endif
