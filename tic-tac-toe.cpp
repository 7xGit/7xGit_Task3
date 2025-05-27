#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int SIZE = 3; 

void printBoard(const vector<vector<char>>& board) {
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << (board[i][j] == ' ' ? '_' : board[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // Check main diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    // Check anti-diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true;
}

// Safe input function to read row and col, validating input type and range
bool getMove(int &row, int &col) {
    if (!(cin >> row >> col)) {
        // Clear error state and ignore invalid input until newline
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
    char currentPlayer = 'X';
    int row, col;

    for (int turn = 0; turn < SIZE * SIZE; ) {  // increment inside loop only on valid move
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        
        if (!getMove(row, col)) {
            cout << "Invalid input. Please enter numeric values for row and column." << endl;
            continue; // ask again, no turn increment
        }

         // Validate range and check if spot already taken
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            cout << "Move out of bounds. Please enter values between 0 and " << SIZE - 1 << "." << endl;
            continue; // ask again, no turn increment
        }

        if (board[row][col] != ' ') {
            cout << "That spot is already taken. Choose another." << endl;
            continue; // ask again, no turn increment
        }

        // Valid move, place mark
        board[row][col] = currentPlayer;
        turn++; // increment turn count on valid move

        
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            return 0;
        }

    
        if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            return 0;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    cout << "Game over!" << endl;

    return 0; 
}
