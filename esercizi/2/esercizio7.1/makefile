all: esercizio7.1
esercizio7.1: esercizio7.1.o integrale.o
	g++ esercizio7.1.o integrale.o -o esercizio7.1
esercizio7.1.o: esercizio7.1.cc integrale.h seno.h funzioneBase.h
	g++ -c esercizio7.1.cc -o esercizio7.1.o
integrale.o: integrale.cc integrale.h
	g++ -c integrale.cc -o integrale.o
