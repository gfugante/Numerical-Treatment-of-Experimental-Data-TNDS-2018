#ifndef _funzioni_h_
#define _funzioni_h_

struct Vettore {
    unsigned int N;
    double* v;
};

void print(const struct Vettore vec, const char* filename);
struct Vettore read(unsigned int N, const char* filename);
void scambia(double &a, double &b);
void ordina(struct Vettore v);

#endif
