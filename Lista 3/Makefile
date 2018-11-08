CC=clang
CFLAGS=-Wextra --pedantic -std=c11
LDFLAGS=-lm

PROGS=zadanie1 zadanie2 zadanie3 \
zadanie4 zadanie5 zadanie6

all: $(PROGS)

analiza:
	@echo
	@echo "*****************************************"
	@echo "**  Analiza statyczna programem clang  **"
	@echo "*****************************************"
	@echo
	clang --analyze *.c

check:
	@echo
	@echo "********************************************"
	@echo "**  Analiza statyczna programem cppcheck  **"
	@echo "********************************************"
	@echo
	cppcheck --enable=all --std=c11 *.c
clean:
	rm -f $(PROGS) *.o *.plist

