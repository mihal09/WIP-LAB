CC=clang
CFLAGS=-Wextra --pedantic -std=c11
LDFLAGS=-lm

all: zadanie1

zadanie1: zadanie1.o palindrom.o
	clang -o zadanie1 zadanie1.o palindrom.o

zadanie1.o: zadanie1.c
	clang -c zadanie1.c

palindrom.o : palindrom.c
	clang -c palindrom.c

clean:
	rm -f main *.o *.plist

