4CC=clang
CFLAGS=-Wextra --pedantic -std=c11
LDFLAGS=-lm

all: main

main: main.o agents.o
	clang -o main main.o agents.o

main.o: main.c
	clang -c main.c

agents.o : agents.c
	clang -c agents.c

clean:
	rm -f main *.o *.plist

