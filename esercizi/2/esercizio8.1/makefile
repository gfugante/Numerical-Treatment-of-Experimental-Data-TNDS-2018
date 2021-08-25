LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all: esercizio8.1
esercizio8.1: esercizio8.1.o Random.o
	g++ esercizio8.1.o Random.o -o esercizio8.1 ${INCS} ${LIBS}
esercizio8.1.o: esercizio8.1.cc Random.h
	g++ -c esercizio8.1.cc -o esercizio8.1.o ${INCS}
Random.o: Random.cc Random.h
	g++ -c Random.cc -o Random.o
