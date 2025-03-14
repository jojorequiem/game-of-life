CC = gcc
CFLAGS = -Wall -g -I./include  
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf
SRC = src/main.c src/game.c src/renderer.c src/config.c src/events.c src/simulation.c src/help.c
OBJ = $(SRC:.c=.o)
EXEC = game_of_life

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
