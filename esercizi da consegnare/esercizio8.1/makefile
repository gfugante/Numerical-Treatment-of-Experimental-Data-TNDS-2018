LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: esercizio8.1

esercizio8.1: main.o Random.o FunzioneBase.o
	g++ main.o Random.o FunzioneBase.o -o esercizio8.1 ${INCS} ${LIBS}

main.o: main.C Random.h FunzioneBase.h
	g++ -c main.C -o main.o ${INCS}
	
Random.o: Random.C Random.h FunzioneBase.h
	g++ -c Random.C -o Random.o

FunzioneBase: FunzioneBase.C FunzioneBase.h
	g++ -c FunzioneBase.C -o FunzioneBase.o
	
clean:
	rm -f *.o esercizio8.1
