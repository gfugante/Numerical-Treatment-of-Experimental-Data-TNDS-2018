#include "particella.hpp"
#include <iostream>
using namespace std;

Particella::Particella (double m, double c)
{
    m_massa=m;
    m_carica=c;
}

Particella::Particella()
{
    m_massa=0;
    m_carica=0;
}

double Particella::GetMassa()
{
    return m_massa;
}

double Particella::GetCarica()
{
    return m_carica;
}

void Particella::Print() const
{
    cout<<"m= "<<m_massa<<endl;
    cout<<"c= "<<m_carica<<endl;
}
