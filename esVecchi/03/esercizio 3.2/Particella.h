#include <iostream>
#include <string>
#ifndef __posizione__
#define __posizione__

class Particella{

	protected:
	double massa, carica;


	public:

	Particella();
	Particella(double massa, double carica);
	~Particella();
	
	double getMassa() const;
	double getCarica() const;
	
	virtual void print() const;

};

class Elettrone : public Particella{
	public:
	Elettrone();
	void print() const;
};

class CorpoCeleste : public Particella{
	public:
	CorpoCeleste (std::string nome, double massa, double raggio);
	~CorpoCeleste();
	void setNome(std::string _nome)	{nome = _nome;};
	void setMassa(double _massa)	{massa=_massa;};
	void setRaggio(double _raggio)	{raggio=_raggio;};
	
	std::string GetNome () const {return nome;}
	double GetMassa () const {return massa;}
	double GetRaggio () const {return raggio;}
	 
	virtual void print () const;
	
	protected:
	double raggio;
	std::string nome;
};

#endif 

