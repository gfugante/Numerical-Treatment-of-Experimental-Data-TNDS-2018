#ifndef particella_hpp
#define particella_hpp

class Particella
{
public:
    Particella (double m, double c);
    Particella ();
    double GetMassa ();
    double GetCarica ();
    virtual void Print () const;
    
protected:
    double m_massa;
    double m_carica;
};

#endif /* particella_hpp */
