#ifndef posizione_hpp
#define posizione_hpp

class Posizione {
    
public:
    Posizione();
    Posizione(double x, double y, double z);
    ~Posizione();
    
    double X() const;
    double Y() const;
    double Z() const;
    double R() const;
    double Phi() const;
    double Theta() const;
    double Rho() const;
    double Distanza(const Posizione&) const;
    
private:
    double m_R, m_Phi, m_Theta;
};



#endif /* posizione_hpp */