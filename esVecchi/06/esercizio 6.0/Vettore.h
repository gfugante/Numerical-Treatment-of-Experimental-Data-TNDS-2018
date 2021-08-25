#ifndef __campo__
#define __campo__


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
		double getComponente(int ) const;
		unsigned int getN() const {return _N;};

};




#endif
