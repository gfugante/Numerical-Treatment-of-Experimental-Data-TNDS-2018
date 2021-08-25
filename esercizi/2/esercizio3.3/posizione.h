#ifndef _posizione_h_
#define _posizione_h_

class posizione{
public:
	posizione();
	posizione(double x, double y, double z);
	~posizione();
	void setposizione(double x, double y, double z);
	double x() const;
	double y() const;
	double z() const;
	
	double R() const;
	double phi() const;
	double theta() const;
	
	double rho() const;

	double distanza(const posizione &) const;
private:
	double _x, _y, _z;
};

#endif


