#ifndef __Vettore_h__
#define __Vettore_h__

class Vettore
{
	protected:
		unsigned int _N;
		double *_v;

	public:
		Vettore();
		Vettore (unsigned int);//unsigned accetta solo numeri privi di segno
		~Vettore();
		
		Vettore(const Vettore&);
		Vettore& operator=(const Vettore&);

		unsigned int GetN() const {return _N;} 
		void SetComponent(unsigned int, double);
		double GetComponent(unsigned int) const;

		void print (const Vettore V);

		double modulo();
};

#endif
