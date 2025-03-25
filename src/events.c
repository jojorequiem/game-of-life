#include "../include/events.h"

#include <SDL2/SDL.h>

#include "../include/config.h"
#include "../include/game.h"

void handleQuitEvent() { running = false; }

void handleKeyDownEvent(SDL_Keycode key, SDL_Keymod mod) {
  if (key == SDLK_ESCAPE) {
    running = false;
  } else if (key == SDLK_1) {
    randomGrid = true;
    fillRandomGrid(grid);
  } else if (key == SDLK_2) {
    randomGrid = false;
    memset(manualGrid, 0, sizeof(manualGrid));
  } else if (key == SDLK_SPACE) {
    simulationRunning = !simulationRunning;
  } else if (key == SDLK_r && (mod & KMOD_SHIFT)) {
    memset(manualGrid, 0, sizeof(manualGrid));
  }
}

void handleMouseButtonDownEvent(SDL_MouseButtonEvent buttonEvent) {
  int x = (buttonEvent.x - offsetX) / (WIDTH / COLS);
  int y = (buttonEvent.y - offsetY) / (HEIGHT / ROWS);

  if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
    if (buttonEvent.button == SDL_BUTTON_LEFT) {
      if (randomGrid)
        grid[y][x] = !grid[y][x];
      else
        manualGrid[y][x] = !manualGrid[y][x];
    } else if (buttonEvent.button == SDL_BUTTON_RIGHT) {
      if (randomGrid)
        grid[y][x] = false;
      else
        manualGrid[y][x] = false;
    }
  }
  dragging = true;
}

void handleMouseButtonUpEvent(SDL_MouseButtonEvent buttonEvent) {
  if (buttonEvent.button == SDL_BUTTON_LEFT) {
    dragging = false;
  }
}

void handleMouseMotionEvent(SDL_MouseMotionEvent motionEvent) {
  if (dragging) {
    offsetX += motionEvent.xrel;
    offsetY += motionEvent.yrel;
  }
}

void handleMouseWheelEvent(SDL_MouseWheelEvent wheelEvent) {
  if (wheelEvent.y > 0) {
    WIDTH += zoomFactor;
    HEIGHT += zoomFactor;
  } else if (wheelEvent.y < 0) {
    if (WIDTH > MIN_WIDTH && HEIGHT > MIN_HEIGHT) {
      WIDTH -= zoomFactor;
      HEIGHT -= zoomFactor;
    }
  }
}

void handleEvents(SDL_Event *event) {
  while (SDL_PollEvent(event)) {
    switch (event->type) {
      case SDL_QUIT:
        handleQuitEvent();
        break;

      case SDL_KEYDOWN:
        handleKeyDownEvent(event->key.keysym.sym, event->key.keysym.mod);
        break;

      case SDL_MOUSEBUTTONDOWN:
        handleMouseButtonDownEvent(event->button);
        break;

      case SDL_MOUSEBUTTONUP:
        handleMouseButtonUpEvent(event->button);
        break;

      case SDL_MOUSEMOTION:
        handleMouseMotionEvent(event->motion);
        break;

      case SDL_MOUSEWHEEL:
        handleMouseWheelEvent(event->wheel);
        break;

      default:
        break;
    }
  }
}
