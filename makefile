
CC=gcc
CFLAGS=-Wall -Wextra
LDFLAGS=
EXEC=main

all: $(EXEC)

main: display.o voiture.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

display.o: ./src/display.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

voiture.o: ./src/voiture.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

main.o: ./src/main.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
