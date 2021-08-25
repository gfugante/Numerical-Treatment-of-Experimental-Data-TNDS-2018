INCS:=` root-config --cflags`
LIBS:=` root-config --libs`


Esercizio: Esercizio.o  integrator.o random.o vettoredati.o vettore.o
	g++ Esercizio.o integrator.o random.o vettoredati.o vettore.o -o Esercizio_9.2  ${INCS} ${LIBS}

Esercizio.o: Esercizio_9.2.cpp sin.h integrator.h random.h
	g++ -c Esercizio_9.2.cpp -o Esercizio.o ${INCS}


random.o: random.cpp random.h 
	g++ -c random.cpp -o random.o 


integrator.o: integrator.cpp integrator.h random.h funzionebase.h 
	g++ -c integrator.cpp -o integrator.o 

vettoredati.o:vettoredati.cpp vettoredati.h vettore.h 
	g++ -c vettoredati.cpp -o vettoredati.o 

vettore.o: vettore.cpp vettore.h
	g++ -c vettore.cpp -o vettore.o 


