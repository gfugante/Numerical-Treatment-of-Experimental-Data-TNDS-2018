all: esercizio7.2

esercizio7.2: esercizio7.2.o Integratore.o Seno.o
	g++ esercizio7.2.o Integratore.o Seno.o -o esercizio7.2

esercizio7.2.o: esercizio7.2.cpp Seno.h Integratore.h
	g++ -c esercizio7.2.cpp -o esercizio7.2.o

Integratore.o: Integratore.cpp Integratore.h FunzioneBase.h
	g++ -c Integratore.cpp -o Integratore.o

Seno.o: Seno.cpp Seno.h FunzioneBase.h
	g++ -c Seno.cpp -o Seno.o

clean:
	rm -f *.o esercizio7.2
