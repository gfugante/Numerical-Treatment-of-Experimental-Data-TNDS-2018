all:esercizio1.3

esercizio1.3: esercizio1.3.o Modulo.o
	g++ esercizio1.3.o Modulo.o -o esercizio1.3

esercizio1.3.o:esercizio1.3.C Modulo.h Modulo.C
	g++ -c esercizio1.3.C -o esercizio1.3.o

Modulo.o: Modulo.h Modulo.C
	g++ -c Modulo.C -o Modulo.o

clean:
	rm -f *.o esercizio1.3
