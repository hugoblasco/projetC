
CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=
EXEC=main

all: $(EXEC)

main: voiture.o display.o run.o main.o
	@echo "début edition des liens : display, voiture, run et main"
	$(CC) -o main voiture.o display.o run.o main.o
	@echo "fin edition des liens"

main.o: ./src/main.c ./headers/main.h
	@echo "début compilation main"
	$(CC) -c ./src/main.c
	@echo "fin compilation main"

run.o: ./src/run.c ./headers/run.h
	@echo "début compilation run"
	$(CC) -c ./src/run.c
	@echo "fin compilation run"

display.o: ./src/display.c ./headers/display.h
	@echo "début compilation display"
	$(CC) -c ./src/display.c
	@echo "fin compilation display"	

voiture.o: ./src/voiture.c ./headers/voiture.h
	@echo "début compilation voiture"
	$(CC) -c ./src/voiture.c
	@echo "fin compilation voiture"	

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
