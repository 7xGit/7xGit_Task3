#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int SIZE = 3;

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << (board[i][j] == ' ' ? '_' : board[i][j]) << " ";
        }
        cout << endl;
    }
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
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
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

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
    char currentPlayer = 'X';
    int row, col;

    for (int turn = 0; turn < SIZE * SIZE; turn++) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";

        // Input validation for numeric values
        while (!(cin >> row >> col)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter two numbers (row and column): ";
        }

        // Validate move
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            turn--;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            return 1;
        }

        if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            return 1;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);
    cout << "Game over!" << endl;

    return 0;
}
