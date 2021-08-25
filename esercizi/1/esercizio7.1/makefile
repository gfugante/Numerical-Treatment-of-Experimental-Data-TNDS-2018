INCS:=` root-config --cflags`
LIBS:=` root-config --libs`

Esercizio: Esercizio.o integrator.o 
	g++ Esercizio.o integrator.o -o Esercizio_7.1

Esercizio.o: Esercizio_7.1.cpp funzionebase.h integrator.h sin.h
	g++ -c Esercizio_7.1.cpp -o Esercizio.o

integrator.o: integrator.cpp integrator.h funzionebase.h
	g++ -c integrator.cpp -o integrator.o




root: 
	g++ -o disegnaROOT disegnaROOT.cpp ${INCS} ${LIBS}

