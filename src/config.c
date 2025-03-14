#include "../include/config.h"

int WIDTH = DEFAULT_WIDTH;
int HEIGHT = DEFAULT_HEIGHT;

bool history[100][ROWS][COLS] = {false};
int history_index = 0;
bool simulationRunning = false;
bool grid[ROWS][COLS] = {false};
bool manualGrid[ROWS][COLS] = {false};
int offsetX = 0, offsetY = 0;
bool dragging = false;
bool randomGrid = false;
int running = 1;
