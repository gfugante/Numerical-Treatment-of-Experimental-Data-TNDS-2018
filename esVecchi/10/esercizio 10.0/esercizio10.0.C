#include <iostream>

#include "Vettore.h"
#include "VettoreLineare.h"

using namespace std;

int main ()
{
	double x, y, z;
	
	VettoreLineare F1(3);
	VettoreLineare F2(3);
	VettoreLineare R(3);
	VettoreLineare P(3);

	cout << "Inserire le componenti di F1: " << endl;
	cin >> x >> y >> z;

	F1.setComponent(0, x);
	F1.setComponent(1, y);
	F1.setComponent(2, z);

	cout << "Inserire le componenti di F2: " << endl;
	cin >> x >> y >> z;
	
	F2.setComponent(0, x);
	F2.setComponent(1, y);
	F2.setComponent(2, z);

	R = (F1 + F2);
	cout << "\nLa risultante R delle forze e': ";
	for (unsigned int i = 0; i < 3; i++)
	{
		cout << R.getComponent(i) << " ";
	}

	cout << endl << "Il coseno tra F1 e R e': " << R.Coseno(F1) << endl;
	cout << "Il coseno tra F2 e R e': " << R.Coseno(F2) << endl;

	P = R.Versore();
	cout << "Il versore della risultante e': ";
	for (unsigned int i = 0; i < 3; i++)
	{
		cout << P.getComponent(i) << " ";
	}

	return 0;
}
