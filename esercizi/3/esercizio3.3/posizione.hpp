#ifndef posizione_hpp
#define posizione_hpp

class Posizione {
    
public:
    Posizione();
    Posizione(double x, double y, double z);
    ~Posizione();
    
    double X() const {return m_X;}
    double Y() const {return m_Y;}
    double Z() const {return m_Z;}
    double Distanza(const Posizione&) const;
    
private:
    double m_X, m_Y, m_Z;
};



#endif /* posizione_hpp */
