#include <SDL2/SDL.h>

#include "../include/config.h"
#include "../include/game.h"

void updateSimulation() {
  if (simulationRunning) {
    bool nextGrid[ROWS][COLS] = {false};
    applyRules(randomGrid ? grid : manualGrid, nextGrid);
    memcpy(randomGrid ? grid : manualGrid, nextGrid, sizeof(grid));
    saveState(grid);
    SDL_Delay(100);
  }
}
