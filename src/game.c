#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/config.h"

void fillRandomGrid(bool grid[ROWS][COLS]) {
  srand(time(NULL));
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

int countNeighbors(bool grid[ROWS][COLS], int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;
      int nx = x + i, ny = y + j;
      if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS) {
        count += grid[nx][ny];
      }
    }
  }
  return count;
}

void applyRules(bool grid[ROWS][COLS], bool nextGrid[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int neighbors = countNeighbors(grid, i, j);
      nextGrid[i][j] = (grid[i][j] && (neighbors == 2 || neighbors == 3)) || (!grid[i][j] && neighbors == 3);
    }
  }
}

void saveState(bool grid[ROWS][COLS]) {
  memcpy(history[history_index], grid, sizeof(history[history_index]));
  history_index = (history_index + 1) % 100;
}

void restoreState(bool grid[ROWS][COLS]) {
  if (history_index > 0) {
    history_index--;
    memcpy(grid, history[history_index], sizeof(history[history_index]));
  }
}
