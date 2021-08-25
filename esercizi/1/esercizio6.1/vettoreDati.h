#ifndef _VETTOREDATI_h
#define _VETTOREDATI_h
#include "vettore.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class vettoreDati: public vettore{
	public:
	vettoreDati(unsigned int N, const char* datainfile);
	void print() const;
	void print (const char* dataoutfile);
	void selectionSort();


};
#endif
	
	
