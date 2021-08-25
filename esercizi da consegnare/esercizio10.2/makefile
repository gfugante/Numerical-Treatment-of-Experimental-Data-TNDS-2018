LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio10.2

esercizio10.2: esercizio10.2.o VettoreLineare.o EquazioniDifferenziali.o Vettore.o
	g++ esercizio10.2.o VettoreLineare.o EquazioniDifferenziali.o Vettore.o -o esercizio10.2 ${INCS} ${LIBS}

esercizio10.2.o: esercizio10.2.cpp VettoreLineare.h EquazioniDifferenziali.h
	g++ -c esercizio10.2.cpp -o esercizio10.2.o ${INCS}

VettoreLineare.o: VettoreLineare.C VettoreLineare.h Vettore.h
	g++ -c VettoreLineare.C -o VettoreLineare.o

EquazioniDifferenziali.o: EquazioniDifferenziali.cpp EquazioniDifferenziali.h VettoreLineare.h 
	g++ -c EquazioniDifferenziali.cpp -o EquazioniDifferenziali.o

Vettore.o: Vettore.C Vettore.h
	g++ -c Vettore.C -o Vettore.o

clean:
	rm -f *.o esercizio10.2
