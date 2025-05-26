#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3; 

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    for (int i = 0; i < SIZE; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
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
        cin >> row >> col;

        // Validate input
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
