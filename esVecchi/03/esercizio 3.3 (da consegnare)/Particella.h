#include <iostream>
#include <string>
#include "Posizione.h"
#ifndef __particella__
#define __particella__

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
	void setMassa(double _massa)	{massa = _massa;};
	void setRaggio(double _raggio)	{raggio = _raggio;};
	void setPosizione(Posizione _r)	{r = _r;};

	std::string GetNome () const {return nome;}
	double getMassa () const {return massa;}
	double getRaggio () const {return raggio;}
	Posizione getPosizione() const {return r;} 	 

	virtual void print () const;
	double potenziale(Posizione R);
	protected:
	double raggio;
	std::string nome;
	Posizione r;
};

#endif 

