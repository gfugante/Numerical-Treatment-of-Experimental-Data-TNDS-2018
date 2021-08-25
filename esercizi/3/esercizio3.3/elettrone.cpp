#include "elettrone.hpp"
#include "particella.hpp"
#include <iostream>
using namespace std;

Elettrone::Elettrone () : Particella(9.1093826E-31, -1.60217635E-19) {}

void Elettrone::Print () const
{
    cout<<"Elettrone: m="<<m_massa<<endl;
    cout<<"q="<<m_carica<<endl;
}
