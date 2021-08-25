
#ifndef __vector__
#define __vector__
#include <string>
using namespace std;

class Vettore{

	protected:
		unsigned int _N;
		double* _v;

	public:

		Vettore();
		~Vettore();
		Vettore(unsigned int N);
		
		Vettore(const Vettore&);
		Vettore& operator=(const Vettore&);


		void setComponente(unsigned int , double );
		double getComponente(unsigned int ) const;
		unsigned int getN() const {return _N;};

};

class VettoreDati : public Vettore{

	public:
		VettoreDati(unsigned int , string );
		~VettoreDati();
		void print() const;
		void print(string);
		void sort();
};


#endif
