# Task 3 - Tic-Tac-Toe Game

## Introduction

This is a simple **Tic-Tac-Toe** game implemented in C++ using a 3x3 grid. Players take turns marking their spots as either 'X' or 'O', and the objective is to get three in a row horizontally, vertically, or diagonally.

## How to Start the Program

### Prerequisites

To run this program, you'll need:
- A C++ compiler (like **g++** or **clang**).
- A terminal or command prompt for running the program.

### Steps to Run the Game

1. **Clone the Repository**  
   Download or clone this repository onto your local machine.

   ```bash
   git clone https://github.com/7xGit/7xGit_Task3.git
   ```

2. **Navigate to the Project Directory**  
   Open your terminal or command prompt and navigate to the directory where the game is saved.

   ```bash
   cd tictactoe
   ```

3. **Compile the Program**  
   Compile the C++ file using a compiler like `g++`:

   ```bash
   g++ tictactoe.cpp -o tictactoe
   ```

4. **Run the Program**  
   After compilation, you can run the game:

   ```bash
   ./tictactoe
   ```

5. **Gameplay Instructions**  
   - The game will prompt each player (Player X and Player O) to input their move.
   - Players should enter the row and column where they want to place their mark.
   - The first player to get three in a row wins!
   - If all spaces are filled without a winner, the game will end in a draw.

### Example Game:

```
  Player X, enter your move (row and column): 0 1
    _ X _
    _ _ _
    _ _ _
    
  Player O, enter your move (row and column): 1 1
    _ X _
    _ O _
    _ _ _
```

## Known Issues

### 1. Players Can Overwrite Each Other’s Moves
Players are allowed to overwrite each other’s moves, which should not happen. Ensure that when a player selects a square, no other player can overwrite it.

### 2. Missing Column Win Check
The program does not currently check for vertical (column) wins. It only verifies horizontal and diagonal wins.

### 3. No Input Validation for Non-Numeric Values
The program does not properly handle non-numeric input, leading to potential crashes. Ensure that only valid inputs (numeric row and column values) are allowed.

### 4. Game Ends Early Due to Incorrect Turn Count
In some cases, the game may end before all turns are used, even though moves are still available. This happens due to incorrect management of the turn count.

## Future Improvements
- Add a more robust input validation system.
- Fix the overwrite bug and ensure no player can replace an already marked cell.
- Implement a column win check to ensure vertical wins are recognized.
- Ensure the game runs for all turns or stops only when a player wins.

