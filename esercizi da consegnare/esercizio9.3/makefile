LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all: esercizio9.3

esercizio9.3: esercizio9.3.o Integratore.o SferaChar.o Vettore.o Random.o Gaussiana.o
	g++ esercizio9.3.o Integratore.o SferaChar.o Vettore.o Random.o Gaussiana.o -o esercizio9.3 ${INCS} ${LIBS}

esercizio9.3.o: esercizio9.3.C Integratore.h SferaChar.h
	g++ -c esercizio9.3.C -o esercizio9.3.o ${INCS}

Integratore.o: Integratore.C Integratore.h Random.h Vettore.h
	g++ -c Integratore.C -o Integratore.o

SferaChar.o: SferaChar.C SferaChar.h FunzioneBase.h
	g++ -c SferaChar.C -o SferaChar.o

Vettore.o: Vettore.C Vettore.h
	g++ -c Vettore.C -o Vettore.o

Random.o: Random.C Random.h Gaussiana.h
	g++ -c Random.C -o Random.o

Gaussiana.o: Gaussiana.C Gaussiana.h FunzioneBase.h
	g++ -c Gaussiana.C -o Gaussiana.o

clean:
	rm -f *.o esercizio9.3
