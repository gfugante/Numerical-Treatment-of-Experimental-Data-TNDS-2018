all: esercizio5.3
esercizio5.3: esercizio5.3.o bisezione.o segno.o
	g++ esercizio5.3.o bisezione.o segno.o -o esercizio5.3
esercizio5.3.o: esercizio5.3.cc bisezione.h meccquant.h segno.h funzioneBase.h solutore.h
	g++ -c esercizio5.3.cc -o esercizio5.3.o
segno.o: segno.cc segno.h
	g++ -c segno.cc -o segno.o
bisezione.o: bisezione.cc bisezione.h segno.h funzioneBase.h
	g++ -c bisezione.cc -o bisezione.o
