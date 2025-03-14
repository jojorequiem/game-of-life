#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "config.h"

void drawGrid(SDL_Renderer *renderer, bool grid[ROWS][COLS]);
void renderFrame(SDL_Renderer *renderer);
void printAsciiGameName();

#endif
