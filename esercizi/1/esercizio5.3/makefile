all: Esercizio.o funzionetan.o bisezione.o  signfunction.o
	g++ Esercizio_5.3.o funzionetan.o bisezione.o signfunction.o -o Esercizio_5.3

Esercizio.o: Esercizio_5.3.cpp funzionebase.h funzionetan.h solutore.h bisezione.h signfunction.h
	g++ -c Esercizio_5.3.cpp -o Esercizio_5.3.o

funzionetan.o: funzionetan.cpp funzionetan.h funzionebase.h
	g++ -c funzionetan.cpp -o funzionetan.o

bisezione.o: bisezione.cpp bisezione.h signfunction.h solutore.h funzionebase.h
	g++ -c bisezione.cpp -o bisezione.o
			
signfunction.o:  signfunction.cpp signfunction.h 
	g++ -c signfunction.cpp -o signfunction.o


