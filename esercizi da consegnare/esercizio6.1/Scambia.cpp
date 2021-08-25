#include "Scambia.h"

void scambiaByValue (double a, double b)
{
	double c;

	c = a;
	a = b;
	b = c;
}

void scambiaByReference (double& a, double& b)
{
	double c;

	c = a;
	a = b;
	b = c;
}

void scambiaByPointer (double *a, double *b)
{
	double c;
	
	c = *a;
	*a = *b;
	*b = c;
}

void Scambia (double& a, double& b)
{
	double c;

	c = a;
	a = b;
	b = c;
}

void Scambia (float& a, float& b)
{
	float c;

	c = a;
	a = b;
	b = c;
}

void Scambia (unsigned int& a, unsigned int& b)
{
	unsigned int c;

	c = a;
	a = b;
	b = c;
}
void Scambia (int& a, int& b)
{
	int c;

	c = a;
	a = b;
	b = c;
}
