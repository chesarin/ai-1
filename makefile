# all:
	# g++ test.cpp Square.cpp -o test
#compiler type set to g++
CC=g++
#flagsh for c++ compiler
CFLAGS=-c -g -Wall

all: test

test: Astar.o test.o Square.o Node.o
	$(CC) Astar.o test.o Square.o Node.o -o test

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

Square.o: Square.cpp
	$(CC) $(CFLAGS) Square.cpp

Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp

Astar.o: Astar.cpp
	$(CC) $(CFLAGS) Astar.cpp

#Queue.o: Queue.cpp
#	$(CC) $(CFLAGS) Queue.cpp
clean:
	rm -rf *o test