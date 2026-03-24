# Checker Game in C++

A semester project developed during my Bachelor's degree using **C++** and **graphics.h**. This project is a two-player desktop implementation of the classic **Checker / Draughts** game, built with old-style Turbo C++ graphics and keyboard-based controls.

## Overview

This project simulates a checkers game on an 8x8 board for two players. It includes:

- Two-player turn-based gameplay
- Piece movement validation
- Capture logic
- King promotion
- Win detection
- Graphical board rendering using `graphics.h`
- Keyboard-controlled selection and movement

The game was created as a semester project to practice programming fundamentals, game logic, arrays, object-oriented concepts, and graphical programming in C++.

## Features

- **8x8 checkerboard** with graphical display
- **Player 1 and Player 2 turns** handled separately
- **Normal and king pieces** supported
- **Valid move checking** for both players
- **Capture/jump mechanics** implemented
- **Automatic promotion to king** when a piece reaches the opposite end
- **Winning condition detection** when the opponent has no remaining normal pieces

## Technologies Used

- **C++**
- **Turbo C++ / Borland Graphics Interface (BGI)**
- `graphics.h`
- `conio.h`
- `dos.h`

## Project Structure

The game logic is mainly built around:

- Global 8x8 arrays to represent the game board and player pieces
- Two classes:
  - `goti1` for Player 1 pieces
  - `goti2` for Player 2 pieces
- Helper functions for:
  - Graphics initialization
  - Board drawing
  - Game state initialization
  - Winner checking

## How the Game Works

- The board is initialized with pieces for both players.
- Each player takes turns moving their pieces.
- Players use the keyboard to select and move pieces.
- The program checks whether a move is valid.
- If a capture is possible and performed, the opponent’s piece is removed.
- When a piece reaches the last row, it becomes a **king**.
- The game ends when one player has no remaining playable pieces.

## Controls

The game is keyboard-controlled:

- **Arrow keys** → move selection on the board
- **Enter** → select a piece / confirm a move
- **Esc** → exit the game

## How to Run

This project was originally written for **Turbo C++** and uses the old BGI graphics library.

### Requirements

- Turbo C++ or a compatible DOS-based C++ environment
- BGI graphics files properly configured
- Graphics path set correctly in the code:

```cpp
initgraph(&gdriver, &gmode, "c:\\tc\\bgi\\");
```

### Steps

1. Open the project in **Turbo C++**.
2. Make sure the BGI path exists on your machine.
3. Compile the source file.
4. Run the program.

## Learning Outcomes

This project helped me strengthen my understanding of:

- C++ classes and functions
- 2D arrays and board representation
- Game state management
- Conditional logic for move validation
- Graphics programming basics
- Problem solving through game development

## Notes

- This project uses **legacy C++ libraries**, so it may not compile directly in modern compilers such as GCC, Clang, or modern Visual Studio without modification.
- It was developed as an academic project, so the focus was on learning and implementing core game logic rather than modern software architecture.

## Future Improvements

Possible future enhancements include:

- Support for modern C++ compilers
- Better user interface
- Scoreboard and restart option
- Sound effects
- Single-player mode with AI
- Multi-capture support
- Cleaner code structure and modularization

## Author

**Afnan Arshad**  
Bachelor’s Semester Project  
Checker Game in C++
