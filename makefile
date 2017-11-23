
CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=
EXEC=main

all: $(EXEC)

main: voiture.o display.o main.o
	@echo "début edition des liens : display, voiture et main"
	$(CC) -o main voiture.o display.o main.o
	@echo "fin edition des liens"

main.o: ./src/main.c
	@echo "début compilation main"
	$(CC) -c ./src/main.c
	@echo "début compilation main"

display.o: ./src/display.c ./headers/voiture.h
	@echo "début compilation display"
	$(CC) -c ./src/display.c
	@echo "début compilation display"	

voiture.o: ./src/voiture.c ./headers/voiture.h
	@echo "début compilation voiture"
	$(CC) -c ./src/voiture.c
	@echo "fin compilation voiture"	

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
