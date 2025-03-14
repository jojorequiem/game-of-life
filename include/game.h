#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#include "config.h"

extern bool grid[ROWS][COLS];

void fillRandomGrid(bool grid[ROWS][COLS]);
int countNeighbors(bool grid[ROWS][COLS], int x, int y);
void applyRules(bool grid[ROWS][COLS], bool nextGrid[ROWS][COLS]);
void saveState(bool grid[ROWS][COLS]);
void restoreState(bool grid[ROWS][COLS]);

#endif
