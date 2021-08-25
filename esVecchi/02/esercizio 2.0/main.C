#include <iostream>
#include "namespace.C"

using namespace std;



int main(){

cout << "Matematica corretta sommo e sottraggo due numeri:" << endl;
cout << math::sette << " - " << math::tre << " = " << math::sottrazione(math::sette,math::tre) << endl;
cout << math::uno << " + " << math::nove << " = " << math::addizione(math::uno,math::nove) << endl;

cout << "Matematica strana:" << endl;
cout << smath::sette << " - " << smath::tre << " = " << smath::sottrazione(smath::sette,smath::tre) << endl;
cout << smath::uno << " + " << smath::nove << " = " << smath::addizione(smath::uno,smath::nove) << endl;

/*cout << "Che matematica:" << endl;
cout << sette << " - " << tre << " = " << sottrazione(sette,tre) << endl;
cout << uno << " + " << nove << " = " << addizione(uno,nove) << endl;
*/



}



