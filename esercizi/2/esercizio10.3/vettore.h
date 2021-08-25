#ifndef _vettore_h_
#define _vettore_h_

class vettore{
	private:
		unsigned int _N;
		double * _v;

	public:
		vettore();
		vettore(unsigned int N);
		~vettore();
		vettore(const vettore &);
		vettore & operator=(const vettore &);

		unsigned int getN() const {return _N;}
		void setComponenti(unsigned int, double);
		double getComponenti(unsigned int) const;
};

#endif
