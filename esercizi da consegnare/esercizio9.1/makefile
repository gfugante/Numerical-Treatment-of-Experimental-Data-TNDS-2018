LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio9.1

esercizio9.1: esercizio9.1.o Integrale.o FunzioneBase.o Random.o Gaussiana.o
	g++ esercizio9.1.o Integrale.o FunzioneBase.o Random.o Gaussiana.o -o esercizio9.1 ${INCS} ${LIBS}

esercizio9.1.o: esercizio9.1.C Integrale.h FunzioneBase.h
	g++ -c esercizio9.1.C -o esercizio9.1.o ${INCS}
	
Integrale.o: Integrale.C Random.h FunzioneBase.h
	g++ -c Integrale.C -o Integrale.o

Random.o: Random.C Gaussiana.h
	g++ -c Random.C -o Random.o

FunzioneBase.o: FunzioneBase.C Random.h
	g++ -c FunzioneBase.C -o FunzioneBase.o

Gaussiana.o: Gaussiana.C FunzioneBase.h
	g++ -c Gaussiana.C -o Gaussiana.o
	
clean:
	rm -f *.o esercizio9.1
