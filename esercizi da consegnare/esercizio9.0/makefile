LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio9.0

esercizio9.0: main.o EsperimentoPrisma.o Random.o Gaussiana.o FunzioneBase.o
	g++ main.o EsperimentoPrisma.o Random.o Gaussiana.o FunzioneBase.o -o esercizio9.0 ${INCS} ${LIBS}

main.o: main.C EsperimentoPrisma.h
	g++ -c main.C -o main.o ${INCS}
	
EsperimentoPrisma.o: EsperimentoPrisma.C Random.h FunzioneBase.h
	g++ -c EsperimentoPrisma.C -o EsperimentoPrisma.o

Random.o: Random.C Gaussiana.h Random.h
	g++ -c Random.C -o Random.o

FunzioneBase.o: FunzioneBase.C FunzioneBase.h
	g++ -c FunzioneBase.C -o FunzioneBase.o
	
Gaussiana.o: Gaussiana.C FunzioneBase.h
	g++ -c Gaussiana.C -o Gaussiana.o

clean:
	rm -f *.o esercizio9.0
