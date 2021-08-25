LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

all: esercizio8.0
esercizio8.0: esercizio8.0.o Random.o
	g++ esercizio8.0.o Random.o -o esercizio8.0 ${INCS} ${LIBS}
esercizio8.0.o: esercizio8.0.cc Random.h
	g++ -c esercizio8.0.cc -o esercizio8.0.o ${INCS}
Random.o: Random.cc Random.h
	g++ -c Random.cc -o Random.o
