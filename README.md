# 15-game-cpp
The 15-Game

# Overview

15-Game (Sum-to-15) is a console-based C++ strategy game where two players alternate selecting numbers from 1 through 9 without repetition. The first player to collect any three numbers that sum to 15 wins. If all numbers are selected and no player reaches a sum-to-15 triplet, the game ends in a draw.

This project implements a complete object-oriented game engine, including turn management, move validation, win detection, and formatted game-state output.

For a quick explanation of the game and strategy:
https://www.youtube.com/watch?v=UafhPUOCM1E

# Game Rules

- Players take turns selecting numbers from 1 to 9.
- Each number can only be chosen once.
- A player wins if any 3 of their selected numbers add up to 15.
- If all numbers are chosen and no player wins, the result is a draw.

# Game Mechanics

The game state is tracked using three `std::vector<int>` containers:

- `choices` — remaining available numbers (starts as 1–9)
- `playerOnePicks` — Player One selections
- `playerTwoPicks` — Player Two selections

Turns alternate using a boolean flag:

- `isPlayerOnesTurn`

# Win Detection Logic

A player wins if any combination of three distinct picks sums to 15.

Win checking is handled by iterating through all unique 3-number combinations of a player’s picks:

- Requires at least 3 picks
- Uses triple nested loops to test all triplets
- Returns true immediately once a valid sum-to-15 triplet is found

# Core Functionality

The `Game` class provides:

- `MakePick()`  
  Prints the current game state, prompts the current player, validates the selection against remaining choices, removes it from the available pool, stores it in the correct player’s pick list, then switches turns.

- `IsWinner(const std::vector<int>& picks)`  
  Determines whether a given pick list contains any 3-number combination summing to 15.

- `IsGameOver()`  
  Returns true if either player has won or if no choices remain.

- `GetGameStatus()`  
  Returns:
  - `1` if Player One wins
  - `2` if Player Two wins
  - `0` if the game is a draw
  - `-1` if the game is still active

- `operator<<`  
  Prints remaining choices followed by each player’s selections in a consistent formatted layout.

# Core Concepts Applied

- Object-Oriented Programming (OOP)
- Encapsulation of game state and turn logic
- Vector-based state tracking for moves and inventory of choices
- Input validation via membership checks + removal (`erase`) from available moves
- Combinatorial win detection using nested iteration
- Operator overloading for clean, readable game-state output

# How to Run

1. Compile the program using a C++ compiler (e.g., g++, clang++)
2. Run the executable
3. Follow prompts for Player One and Player Two until the game ends
4. The program prints the final board state and announces the result
