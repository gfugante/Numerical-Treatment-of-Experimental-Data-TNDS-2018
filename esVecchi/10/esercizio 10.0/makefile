all:esercizio10.0

esercizio10.0: esercizio10.0.o VettoreLineare.o Vettore.o
	g++ esercizio10.0.o VettoreLineare.o Vettore.o -o esercizio10.0

esercizio10.0.o: esercizio10.0.C VettoreLineare.h Vettore.h
	g++ -c esercizio10.0.C -o esercizio10.0.o

VettoreLineare.o: VettoreLineare.C VettoreLineare.h Vettore.h
	g++ -c VettoreLineare.C -o VettoreLineare.o

Vettore.o: Vettore.C Vettore.h
	g++ -c Vettore.C -o Vettore.o

clean:
	rm -f *.o esercizio10.0
