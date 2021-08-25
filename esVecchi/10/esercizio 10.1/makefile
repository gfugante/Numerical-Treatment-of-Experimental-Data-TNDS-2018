LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio10.1

esercizio10.1: esercizio10.1.o VettoreLineare.o EquazioniDifferenziali.o Vettore.o
	g++ esercizio10.1.o VettoreLineare.o EquazioniDifferenziali.o Vettore.o -o esercizio10.1 ${INCS} ${LIBS}

esercizio10.1.o: esercizio10.1.cpp VettoreLineare.h EquazioniDifferenziali.h
	g++ -c esercizio10.1.cpp -o esercizio10.1.o ${INCS}

VettoreLineare.o: VettoreLineare.cpp VettoreLineare.h Vettore.h
	g++ -c VettoreLineare.cpp -o VettoreLineare.o

EquazioniDifferenziali.o: EquazioniDifferenziali.cpp EquazioniDifferenziali.h VettoreLineare.h 
	g++ -c EquazioniDifferenziali.cpp -o EquazioniDifferenziali.o

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

clean:
	rm -f *.o esercizio10_1
