#ifndef _particelle_h_
#define _particelle_h_

class particelle{
public:
	particelle(double massa, double carica);
	~particelle();
	double getmassa() const{return _massa;};
	double getcarica() const{return _carica;};
	
	virtual void print() const;
protected:
	double _massa, _carica;
};
#endif


