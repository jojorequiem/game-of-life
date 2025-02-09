#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ROWS 100
#define COLS 100
#define TITLE "Game of Life"
#define HEIGHT 800
#define WIDTH 800
#define COLOR_WHITE 255, 255, 255, 255
#define COLOR_BLACK 0, 0, 0, 255
#define COLOR_DARK_GRAY 50, 50, 50, 255

void drawGrid(SDL_Renderer *renderer, bool grid[ROWS][COLS]) {
  int cellWidth = WIDTH / COLS;
  int cellHeight = HEIGHT / ROWS;

  // draw cells
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (grid[i][j]) {
        SDL_SetRenderDrawColor(renderer, COLOR_WHITE);
      } else {
        SDL_SetRenderDrawColor(renderer, COLOR_BLACK);
      }
      SDL_Rect cell = {j * cellWidth, i * cellHeight, cellWidth, cellHeight};
      SDL_RenderFillRect(renderer, &cell);
    }
  }

  // draw background grid
  SDL_SetRenderDrawColor(renderer, COLOR_DARK_GRAY);
  for (int i = 0; i <= ROWS; i++) {
    SDL_RenderDrawLine(renderer, 0, i * cellHeight, WIDTH, i * cellHeight);
  }
  for (int j = 0; j <= COLS; j++) {
    SDL_RenderDrawLine(renderer, j * cellWidth, 0, j * cellWidth, HEIGHT);
  }
}

void initWindow(SDL_Window *window, SDL_Renderer *renderer, bool grid[ROWS][COLS]) {
  int running = 1;
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }
    }
    SDL_SetRenderDrawColor(renderer, COLOR_BLACK);
    SDL_RenderClear(renderer);

    drawGrid(renderer, grid);
    SDL_RenderPresent(renderer);
  }
}
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
      int nx = x + i;
      int ny = y + j;

      if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS) {
        if (grid[nx][ny]) {
          count++;
        }
      }
    }
  }
  return count;
}

void applyRules(bool grid[ROWS][COLS], bool nextGrid[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int neighbors = countNeighbors(grid, i, j);
      if (grid[i][j]) {
        if (neighbors < 2 || neighbors > 3) {
          nextGrid[i][j] = false;
        } else {
          nextGrid[i][j] = true;
        }
      } else {
        if (neighbors == 3) {
          nextGrid[i][j] = true;
        } else {
          nextGrid[i][j] = false;
        }
      }
    }
  }
}

void displayGrid(bool grid[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main(void) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  bool grid[ROWS][COLS] = {false};
  bool nextGrid[ROWS][COLS] = {false};

  fillRandomGrid(grid);

  SDL_Event event;
  int running = 1;
  int iteration = 0;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = 0;
      }

      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        applyRules(grid, nextGrid);
        memcpy(grid, nextGrid, sizeof(grid));
        iteration++;
        printf("Iteration n° %d\n", iteration);
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    drawGrid(renderer, grid);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
