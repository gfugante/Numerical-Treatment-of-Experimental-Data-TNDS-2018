#ifndef _vettoredati_h_
#define _vettoredati_h_
#include "vettore.h"

class vettoredati: public vettore{
	public:
		vettoredati(unsigned int N, const char * filename);
		vettoredati(unsigned int );
		~vettoredati();

		void print();
		void print(const char *);
		void ordina();
		
		double media();
		double dev_st();
};

#endif
