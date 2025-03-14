#include <stdio.h>

void printHelp() {
  printf("\nGame of Life - Help\n");
  printf("====================\n");
  printf("Commands:\n");
  printf("  [1]  - Randomly populate the grid with cells\n");
  printf("  [2]  - Clear the grid\n");
  printf("  [SPACE] - Toggle the simulation on/off\n");
  printf("  [ESC]  - Exit the game\n");
  printf("  [R]    - Reset the grid to the default state (manual grid)\n");
  printf("  [ENTER] - Change grid dimensions (default 10x10)\n");
  printf("  [Arrow keys] - Move the grid (when dragging is active)\n");
  printf("  [Mouse Left Click] - Toggle cell state in the grid\n");
  printf("  [Mouse Right Click] - Reset cell state in the grid\n");
  printf("  [Mouse Wheel] - Zoom in/out on the grid\n");
  printf("\nFor more detailed instructions, check the game documentation.\n");
}
