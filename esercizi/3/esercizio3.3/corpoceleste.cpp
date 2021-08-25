#include "particella.hpp"
#include "corpoceleste.hpp"
#include "posizione.hpp"
#include <string>
#include <cmath>

CorpoCeleste::CorpoCeleste(string nome, double m, double r) : Particella (m, 0)
{
    m_nome=nome;
    m_raggio=r;
}

void CorpoCeleste::SetMassa (double m)
{
    m_massa=m;
}

void CorpoCeleste::SetNome (string nome)
{
    m_nome=nome;
}

void CorpoCeleste::SetRaggio (double r)
{
    m_raggio=r;
}

double CorpoCeleste::GetRaggio()
{
    return m_raggio;
}

void CorpoCeleste::SetPosizione(Posizione p)
{
    m_posizione=p;
}

Posizione CorpoCeleste::GetPosizione ()
{
    return m_posizione;
}

void CorpoCeleste::Print () const
{
    cout<<"Corpo celeste: nome= "<<m_nome<<endl;
    cout<<"m= "<<m_massa<<endl;
    cout<<"raggio= "<<m_raggio<<endl;
}

double CorpoCeleste::Potenziale (Posizione R)
{
    double G=6.67E-11;
	double distanza=m_posizione.Distanza(R);
    return (G*m_massa)/distanza;
}
