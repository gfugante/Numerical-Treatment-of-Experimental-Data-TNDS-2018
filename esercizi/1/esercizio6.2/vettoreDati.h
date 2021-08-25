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
	void sort();
	void calcolaMedia();
	void varianza();
	void devSt();
	double mediana();
	double coeffCorrelazione(vettoreDati& v);
	double getMedia() const{return _media;}
	double getDevSt() const{return _devSt;}
	double getVarianza() const{return _varianza;}
private:
void scambia(unsigned int primo, unsigned int secondo);
void quicksort(unsigned int primo, unsigned int ultimo);
double _media, _devSt, _varianza;
};
#endif
	
	
