#ifndef __Vettore_h__
#define __Vettore_h__


class Vettore
{
	public:
		Vettore();
		Vettore (unsigned int);
		~Vettore();
		
		Vettore(const Vettore&);
		Vettore& operator=(const Vettore&);

		unsigned int GetN() const {return _N;} 
		void SetComponent(unsigned int, double);
		double GetComponent(unsigned int) const;
		void print()const;

		double Varianza() const;
		double Media() const;
		double DevSt() const;
		double Correlazione(const Vettore&) const;

	protected:
		unsigned int _N;
		double *_v;
};

#endif
