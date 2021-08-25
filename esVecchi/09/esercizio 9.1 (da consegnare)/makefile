LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio9.1

esercizio9.1: esercizio9.1.o Integrale.o FunzioneBase.o Random.o Gaussiana.o
	g++ esercizio9.1.o Integrale.o FunzioneBase.o Random.o Gaussiana.o -o esercizio9.1 ${INCS} ${LIBS}

esercizio9.1.o: esercizio9.1.cpp Integrale.h FunzioneBase.h
	g++ -c esercizio9.1.cpp -o esercizio9.1.o ${INCS}
	
Integrale.o: Integrale.cpp Random.h FunzioneBase.h
	g++ -c Integrale.cpp -o Integrale.o

Random.o: Random.cpp Gaussiana.h
	g++ -c Random.cpp -o Random.o

FunzioneBase.o: FunzioneBase.cpp Random.h
	g++ -c FunzioneBase.cpp -o FunzioneBase.o

Gaussiana.o: Gaussiana.cpp FunzioneBase.h
	g++ -c Gaussiana.cpp -o Gaussiana.o
	
clean:
	rm -f *.o main
