# So Long: A 2D Game using the 42 MLX42 library

This repository contains the code for a simple 2D game called "So Long." In this game, a dolphin (or any character of your choice) needs to collect all the collectibles on the map and exit through the shortest route possible. The game uses the MiniLibX library for graphics and follows specific rules for map components and gameplay.

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Map Configuration](#map-configuration)

## Requirements

- A Unix-based system with the MiniLibX library installed
- A C compiler, such as gcc
- Make utility for building the project

## Installation

1. Clone the repository:

   ```
   git clone https://github.com/your_username/so_long.git
   ```

2. Change to the project directory:

   ```
   cd so_long
   ```

3. Compile the project:

   ```
   make
   ```

## Usage

1. Run the game with a map file in `.ber` format:

   ```
   ./so_long maps/sample_map.ber
   ```

2. Use the W, A, S, and D keys to move the character in the game. Collect all the collectibles on the map and find the shortest route to exit.

3. Press ESC or click the cross on the window's frame to close the game window and exit the program.

## Map Configuration

A valid map file must contain the following components:

- Walls, represented by the number `1`
- Collectibles, represented by the letter `C`
- Free space, represented by the number `0`
- One exit, represented by the letter `E`
- One starting position, represented by the letter `P`

The map must be rectangular, closed/surrounded by walls, and have a valid path for the character. If the map contains any misconfiguration, the program will exit and display an error message.

Here is an example of a valid map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

For more information on map configuration, please refer to the [project description](#project-description).

