CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11
LDFLAGS = -lm -lSDL2

main: main.c
	$(CC) -o main main.c $(CFLAGS) $(LDFLAGS)

clean:
	rm -f main
