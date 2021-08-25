INCS:=` root-config --cflags`
LIBS:=` root-config --libs`


Esercizio: Esercizio.o esperimentoprisma.o vettoredati.o random.o vettore.o 
	g++ Esercizio.o esperimentoprisma.o vettoredati.o random.o vettore.o -o Esercizio_9.0  ${INCS} ${LIBS}

Esercizio.o: Esercizio_9.0.cpp esperimentoprisma.h vettoredati.h vettore.h random.h
	g++ -c Esercizio_9.0.cpp -o Esercizio.o ${INCS}

esperimentoprisma.o: esperimentoprisma.cpp esperimentoprisma.h random.h
	g++ -c esperimentoprisma.cpp -o esperimentoprisma.o 

random.o: random.cpp random.h 
	g++ -c random.cpp -o random.o 


vettoredati.o: vettoredati.cpp vettoredati.h vettoredati.h vettore.h
	g++ -c vettoredati.cpp -o vettoredati.o 


vettore.o: vettore.cpp vettore.h 
	g++ -c vettore.cpp -o vettore.o 



