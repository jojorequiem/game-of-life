#include "../include/renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "../include/config.h"

void drawGrid(SDL_Renderer *renderer, bool grid[ROWS][COLS]) {
  int cellWidth = WIDTH / COLS;
  int cellHeight = HEIGHT / ROWS;

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      SDL_SetRenderDrawColor(renderer, grid[i][j] ? 255 : 0, grid[i][j] ? 255 : 0, grid[i][j] ? 255 : 0, 255);
      SDL_Rect cell = {j * cellWidth + offsetX, i * cellHeight + offsetY, cellWidth, cellHeight};
      SDL_RenderFillRect(renderer, &cell);
    }
  }

  SDL_SetRenderDrawColor(renderer, COLOR_DARK_GRAY);
  for (int i = 0; i <= ROWS; i++) {
    SDL_RenderDrawLine(renderer, 0 + offsetX, i * cellHeight + offsetY, WIDTH + offsetX, i * cellHeight + offsetY);
  }
  for (int j = 0; j <= COLS; j++) {
    SDL_RenderDrawLine(renderer, j * cellWidth + offsetX, 0 + offsetY, j * cellWidth + offsetX, HEIGHT + offsetY);
  }
}
void drawText(SDL_Renderer *renderer, TTF_Font *font, const char *text, int x, int y) {
  SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, (SDL_Color){255, 255, 255, 255});
  SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
  SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
  SDL_FreeSurface(textSurface);
  SDL_DestroyTexture(textTexture);
}

void renderFrame(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  drawGrid(renderer, randomGrid ? grid : manualGrid);
  SDL_RenderPresent(renderer);
}

void printAsciiGameName() {
  printf("\n");

  printf(" ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ███████╗    ██╗     ██╗███████╗███████╗\n");
  printf("██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██╔════╝    ██║     ██║██╔════╝██╔════╝\n");
  printf("██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║█████╗      ██║     ██║█████╗  █████╗  \n");
  printf("██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║██╔══╝      ██║     ██║██╔══╝  ██╔══╝  \n");
  printf("╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝██║         ███████╗██║██║     ███████╗\n");
  printf(" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝ ╚═╝         ╚══════╝╚═╝╚═╝     ╚══════╝\n");
  printf("\n");
  printf("                                        @jojorequiem");
  printf("\n");
  printf("\n");
}
