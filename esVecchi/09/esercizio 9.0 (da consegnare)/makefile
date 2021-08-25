LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: main

main: main.o EsperimentoPrisma.o Random.o Gaussiana.o FunzioneBase.o
	g++ main.o EsperimentoPrisma.o Random.o Gaussiana.o FunzioneBase.o -o main ${INCS} ${LIBS}

main.o: main.cpp EsperimentoPrisma.h
	g++ -c main.cpp -o main.o ${INCS}
	
EsperimentoPrisma.o: EsperimentoPrisma.cpp Random.h FunzioneBase.h
	g++ -c EsperimentoPrisma.cpp -o EsperimentoPrisma.o

Random.o: Random.cpp Gaussiana.h Random.h
	g++ -c Random.cpp -o Random.o

FunzioneBase.o: FunzioneBase.cpp FunzioneBase.h
	g++ -c FunzioneBase.cpp -o FunzioneBase.o
	
Gaussiana.o: Gaussiana.cpp FunzioneBase.h
	g++ -c Gaussiana.cpp -o Gaussiana.o

clean:
	rm -f *.o main
