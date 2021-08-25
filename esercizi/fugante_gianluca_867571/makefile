INCS = `root-config --cflags`
LIBS = `root-config --libs`

all:compito

compito: main.o FunzioneIntegrale.o Integratore.o 
	g++ main.o FunzioneIntegrale.o Integratore.o -o compito $(INCS) $(LIBS)

main.o: main.C Integratore.h FunzioneIntegrale.h
	g++ -c main.C -o main.o $(INCS)

FunzioneIntegrale.o: FunzioneIntegrale.C FunzioneIntegrale.h
	g++ -c FunzioneIntegrale.C -o FunzioneIntegrale.o

Integratore.o: Integratore.C Integratore.h FunzioneBase.h
	g++ -c Integratore.C -o Integratore.o


clean:
	rm -f *.o compito
