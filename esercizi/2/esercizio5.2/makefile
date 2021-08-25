all: esercizio5.2
esercizio5.2: esercizio5.2.o bisezione.o parabola.o segno.o
	g++ esercizio5.2.o bisezione.o parabola.o segno.o -o esercizio5.2
esercizio5.2.o: esercizio5.2.cc bisezione.h parabola.h segno.h funzioneBase.h solutore.h
	g++ -c esercizio5.2.cc -o esercizio5.2.o
segno.o: segno.cc segno.h
	g++ -c segno.cc -o segno.o
parabola.o: parabola.cc parabola.h funzioneBase.h
	g++ -c parabola.cc -o parabola.o
bisezione.o: bisezione.cc bisezione.h parabola.h segno.h funzioneBase.h
	g++ -c bisezione.cc -o bisezione.o
