main: main.o imageio.o funcs.o
	g++ -o main main.o imageio.o funcs.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp imageio.h
	g++ -c main.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp

clean:
	rm -f *.o main sample imageio
