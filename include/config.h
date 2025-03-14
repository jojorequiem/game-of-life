
#ifndef CONFIG_H
#define CONFIG_H
#include <stdbool.h>

#define TITLE "Game of Life"
#define DEFAULT_HEIGHT 800
#define DEFAULT_WIDTH 800

#define ROWS 40
#define COLS 40

#define COLOR_WHITE 255, 255, 255, 255
#define COLOR_BLACK 0, 0, 0, 255
#define COLOR_DARK_GRAY 50, 50, 50, 255

#define FONT_PATH "assets/OpenSans.ttf"

extern int WIDTH;
extern int HEIGHT;

extern bool history[100][ROWS][COLS];
extern int history_index;
extern bool simulationRunning;
extern bool grid[ROWS][COLS];
extern bool manualGrid[ROWS][COLS];
extern int offsetX, offsetY;
extern bool dragging;
extern bool randomGrid;

extern int running;

#endif
