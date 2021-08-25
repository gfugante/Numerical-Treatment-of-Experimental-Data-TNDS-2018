#include "posizione.hh"
#ifndef _particella_h_
#define _particella_h_
#include <string>
using namespace std;

class particella{
	
	public:
	particella();
	particella(double m, double q);
	~particella();
	
	double getMassa() const {return m_m;};
	double getCarica() const {return m_q;};
	virtual void print() const;


	protected:
	double m_m, m_q;

};

class elettrone:public particella{
	public:
	elettrone();
	~elettrone();

	void print() const;	
};


class corpoceleste:public particella{
	public:
	corpoceleste();
	/*corpoceleste (string nome, double m, double r);*/
	corpoceleste (string nome, double m, double r, double x, double y, double z);
	~corpoceleste();
	
	void  setNome(string nome);
	void setMassa(double massa);
	void setRaggio(double raggio);
	string getNome() const;
	double getRaggio() const;
	virtual void printCorpoceleste() const;
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	double getX()const;
	double getY()const;
	double getZ()const;
	virtual void printPosizione() const;
	double potenziale (const posizione&r) const;
	
	
	protected:
	double m_r;
	string m_nome;
	posizione p;
};
#endif 
