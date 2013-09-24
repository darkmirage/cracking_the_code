all: solution.bin

solution.bin: main.o
	g++ main.o -o solution.bin

main.o: main.cc
	g++ -c main.cc

clean:
	rm -rf *o solution.bin