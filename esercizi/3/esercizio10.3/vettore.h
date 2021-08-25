#ifndef _VETTORE_h_
#define _VETTORE_h_

class vettore{
	public:
	vettore();
	vettore(unsigned int N);
	~vettore();
	vettore (const vettore&);//copy constructor
	vettore& operator=(const vettore&);//operatore di assegnazione
	
	unsigned int getN() const {return m_N;}//accede alla dimensione
	void setComponent(unsigned int i, double value){m_v[i]=value;}//modifica la componente passata
	double getComponent(unsigned int i) const {return m_v[i];}//accede alla componente
	void switchComponent(unsigned int i, unsigned int j);
	protected:
	unsigned int m_N;
	double* m_v;
};

#endif
