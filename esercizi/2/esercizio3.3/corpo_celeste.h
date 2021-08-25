#ifndef _corpo_celeste_h_
#define _corpo_celeste_h_
#include <string>
#include "particelle.h"
#include "posizione.h"

class corpo_celeste: public particelle{
public:
	corpo_celeste(std::string nome, double massa, double raggio);
	~corpo_celeste();
	
	void setnome(std::string nome);
	void setmassa(double massa);
	void setraggio(double raggio);
	void setposizione(double x, double y, double z);

	double getpotenziale(const posizione &r) const;
	double getx() const;
	double gety() const;
	double getz() const;
	double getdistanza(const posizione &r) const;

	posizione getposizione() const;
	
	std::string getnome() const;
	double getraggio() const;
		

	virtual void print() const; 

	void printposizione() const;
protected:
	std::string _nome;
	double _raggio;
	posizione _r;
};

#endif
