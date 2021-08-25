#ifndef _vettoredati_h_
#define _vettoredati_h_
#include "vettore.h"

class vettoredati: public vettore{
	public:
		vettoredati(unsigned int N, const char * filename);
		~vettoredati();

		void print();
		void print(const char *);
		void ordina();
};

#endif
