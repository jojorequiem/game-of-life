#include "../include/events.h"

#include <SDL2/SDL.h>

#include "../include/config.h"
#include "../include/game.h"

void handleEvents(SDL_Event *event) {
  while (SDL_PollEvent(event)) {
    if (event->type == SDL_QUIT)
      running = 0;

    else if (event->type == SDL_KEYDOWN) {
      if (event->key.keysym.sym == SDLK_ESCAPE)
        running = 0;
      else if (event->key.keysym.sym == SDLK_1) {
        randomGrid = true;
        fillRandomGrid(grid);
      } else if (event->key.keysym.sym == SDLK_2) {
        randomGrid = false;
        memset(manualGrid, 0, sizeof(manualGrid));
      } else if (event->key.keysym.sym == SDLK_SPACE)
        simulationRunning = !simulationRunning;
      else if (event->key.keysym.sym == SDLK_r && (event->key.keysym.mod & KMOD_SHIFT)) {
        memset(manualGrid, 0, sizeof(manualGrid));
      }
    }

    else if (event->type == SDL_MOUSEBUTTONDOWN) {
      if (event->button.button == SDL_BUTTON_LEFT) {
        int x = (event->button.x - offsetX) / (WIDTH / COLS);
        int y = (event->button.y - offsetY) / (HEIGHT / ROWS);
        if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
          if (randomGrid)
            grid[y][x] = !grid[y][x];
          else
            manualGrid[y][x] = !manualGrid[y][x];
        }
        dragging = true;
      } else if (event->button.button == SDL_BUTTON_RIGHT) {
        int x = (event->button.x - offsetX) / (WIDTH / COLS);
        int y = (event->button.y - offsetY) / (HEIGHT / ROWS);
        if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
          if (randomGrid)
            grid[y][x] = false;
          else
            manualGrid[y][x] = false;
        }
      }
    }

    else if (event->type == SDL_MOUSEBUTTONUP) {
      if (event->button.button == SDL_BUTTON_LEFT) dragging = false;
    }

    else if (event->type == SDL_MOUSEMOTION) {
      if (dragging) {
        offsetX += event->motion.xrel;
        offsetY += event->motion.yrel;
      }
    }

    else if (event->type == SDL_MOUSEWHEEL) {
      if (event->wheel.y > 0) {
        WIDTH += 50;
        HEIGHT += 50;
      } else if (event->wheel.y < 0) {
        if (WIDTH > 100 && HEIGHT > 100) {
          WIDTH -= 50;
          HEIGHT -= 50;
        }
      }
    }
  }
}
