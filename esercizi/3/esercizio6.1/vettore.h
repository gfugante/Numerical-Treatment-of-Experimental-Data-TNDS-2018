#ifndef _Vettore_h_
#define _Vettore_h_

class Vettore{
public:
	Vettore();
	Vettore(unsigned int N);
	~Vettore();
	unsigned int GetN() const {return m_N;}
	void SetComponent(unsigned int, double);
	double GetComponent(unsigned int) const;
	Vettore(const Vettore&);
	Vettore& operator=(const Vettore&);
protected:
	unsigned int m_N;
	double* m_v;
};
#endif
