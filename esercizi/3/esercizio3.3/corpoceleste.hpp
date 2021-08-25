#ifndef corpoceleste_hpp
#define corpoceleste_hpp

#include "particella.hpp"
#include "posizione.hpp"
#include <string>
#include <iostream>
using namespace std;

class CorpoCeleste :public Particella
{
public:
    CorpoCeleste(string nome, double m, double r);
    void SetMassa (double m);;
    void SetNome (string nome);
    void SetRaggio (double r);
    double GetRaggio();
    void SetPosizione(Posizione p);
    Posizione GetPosizione();
    void Print() const;
    double Potenziale(Posizione R);
    
private:
    string m_nome;
    double m_raggio;
    Posizione m_posizione;
};

#endif /* corpoceleste_hpp */
