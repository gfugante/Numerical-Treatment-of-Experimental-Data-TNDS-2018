

struct Vettore{
	unsigned int N;
	double *v;
};

struct Vettore read(unsigned int , const char* );

void print(const struct Vettore);

void print(const struct Vettore vett, const char* filename);

void selectionSort(double [],int );

void selection_sort(struct Vettore);

void scambia(double *,double *);


