#ifndef __vector__
#define __vector__

using namespace std;

class Vettore{

	protected:
		unsigned int _N;
		double* _v;

	public:

		Vettore();
		~Vettore();
		Vettore(unsigned int N);
		

		void setComponent(unsigned int , double );
		double getComponent(unsigned int ) const;
		unsigned int getN() const {return _N;};

		Vettore& operator= (const Vettore&);
		Vettore(const Vettore&);
};

#endif
