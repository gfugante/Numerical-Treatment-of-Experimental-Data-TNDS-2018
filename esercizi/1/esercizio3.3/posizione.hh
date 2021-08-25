#ifndef _posizione_h_
#define _posizione_h_

class posizione{
	
	public:
	posizione();
	posizione(double x, double y,double z);
	~posizione();
	
	double x() const;
	double y() const;
	double z() const;
	double r() const;
	double phi() const;
	double theta() const;
	double rho() const;
	double distanza(const posizione&) const;
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	private:
	double m_x, m_y, m_z;

};

#endif 
