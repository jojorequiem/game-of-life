# Game of Life

## Description:
The **Game of Life** is a cellular automaton devised by the British mathematician **John Conway** in 1970. The game simulates the evolution of a grid of cells based on a set of simple rules that determine whether each cell survives or dies in the next generation. Although it is called a "game", it is a zero-player game, meaning its evolution is determined by its initial state, with no further input from humans.

Conway's Game of Life became popular due to its simplicity and ability to simulate complex patterns from very simple rules. It is often used as an example in computer science to demonstrate the concept of cellular automata.

This project is an implementation of Conway's Game of Life written in **C** using **SDL2** for graphics rendering.

## Features:
- **Fixed grid size**: The default grid size is 10x10.
- **Random grid generation**: Generate a random initial state for the grid.
- **Manual grid editing**: Click to toggle cell states manually.
- **Simulation control**: Start or pause the simulation with the spacebar.
- **Zoom functionality**: Use the mouse wheel to zoom in or out of the grid.
- **History tracking**: Undo and restore previous grid states.
- **Help menu**: View command-line arguments and usage instructions.

## Installation:
### Prerequisites:
This project requires the following dependencies:
- **SDL2**: Simple DirectMedia Layer 2 (SDL2) and SDL2_tf libraries for graphics rendering and font handling.
- **GCC**: The GNU C Compiler (or similar) to build the project.

### Install dependencies:
On **Ubuntu** or **Debian-based** systems, you can install the required libraries and project using the following commands:

```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-ttf-dev build-essential
git clone https://github.com/jojorequiem/game-of-life.git
cd game-of-life
make
./game_of_life
```

Enjoy playing with this simple yet fascinating simulation of Conway's Game of Life
