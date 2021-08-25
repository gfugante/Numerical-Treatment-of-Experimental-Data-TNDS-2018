all: esercizio7.2
esercizio7.2: esercizio7.2.o integrale.o
	g++ esercizio7.2.o integrale.o -o esercizio7.2
esercizio7.2.o: esercizio7.2.cc integrale.h funzioneBase.h seno.h
	g++ -c esercizio7.2.cc -o esercizio7.2.o
integrale.o: integrale.cc integrale.h funzioneBase.h
	g++ -c integrale.cc -o integrale.o
