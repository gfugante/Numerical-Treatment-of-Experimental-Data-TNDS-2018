#include "particella.hh"
#include <cmath>
#include <iostream>

using namespace std;

particella::particella(){
	m_m=0.;
	m_q=0.;
}

particella::particella(double m, double q){
	m_m=m;
	m_q=q;
}

particella::~particella(){
}

void particella::print() const{ 
	cout<<"m="<<m_m<<" q="<<m_q<<endl;
}

elettrone::elettrone():particella(9.1093826E-31,-1.60217653E-19){
	}

elettrone::~elettrone(){
	}

void elettrone::print() const {
	cout<<"m="<<m_m<<", q="<<m_q<<endl;
	}

corpoceleste::corpoceleste():particella(){
	m_r=0.;
	m_nome="Unknown";
	p=posizione();
	}

/*corpoceleste::corpoceleste(std::string nome, double m, double r):particella (m,0.){
	m_nome=nome;
	m_r=r;
	}*/

corpoceleste::corpoceleste(std::string nome, double m, double r, double x,double y, double z):particella (m,0.){
	m_nome=nome;
	m_r=r;
	p=posizione(x,y,z);
	}
	
void corpoceleste::setNome(std::string nome){
	m_nome=nome;
	}

void corpoceleste::setMassa(double a){
	m_m=a;
	}

void corpoceleste::setRaggio(double r){
	m_r=r;
	}

string corpoceleste::getNome() const{
	return m_nome;
	}


double corpoceleste::getRaggio () const{
	return m_r;
	}

void corpoceleste::printCorpoceleste() const{
	cout<<m_nome<<" m="<<m_m<<", r="<<m_r<<endl;
	}

void corpoceleste::printPosizione() const{
	cout<<"x="<<p.x()<<" y="<<p.y()<<" z="<<p.z()<<endl;
	}

double corpoceleste::getX()const{
	return p.x();
	}

double corpoceleste::getY()const{
	return p.y();
	}

double corpoceleste::getZ()const{
	return p.z();
	}

void corpoceleste::setX(double x){
	p.setX(x);
	}

void corpoceleste::setY(double y){
	p.setY(y);
	}

void corpoceleste::setZ(double z){
	p.setZ(z);
	}

double corpoceleste::potenziale(const posizione &a)const{
	double r=p.distanza(a);
	double G=6.67E-11;
	return -(m_m*G)/r;
	}


