#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "../include/config.h"
#include "../include/events.h"
#include "../include/help.h"
#include "../include/renderer.h"
#include "../include/simulation.h"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
      printHelp();
      return 0;
    } else {
      fprintf(stderr, "Error: Unknown argument '%s'. Use --help or -h for usage.\n", argv[1]);
      return 1;
    }
  }
  printAsciiGameName();
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;
  while (running) {
    handleEvents(&event);
    updateSimulation();
    renderFrame(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  TTF_Quit();
  return 0;
}
