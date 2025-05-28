#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 3; 

void printBoard(const vector<vector<char>>& board) {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            cout << board[i][j] <<"_";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 1; i <= SIZE; i++) {
        if (board[i][1] == player && board[i][2] == player && board[i][3] == player)
            return true;
    }

    // Added win condition for column
    for (int i = 1; i <= SIZE; i++) {
        if (board[1][i] == player && board[2][i] == player && board[3][i] == player)
            return true;
    }

    if (board[1][1] == player && board[2][2] == player && board[3][3] == player)
        return true;

    // Added second diagonal win codition
    if (board[1][3] == player && board[2][2] == player && board[3][1] == player)
        return true;

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true;
}

int main() {
    vector<char> rows(SIZE+1, ' ');            
    vector<vector<char>> board(SIZE+1, rows);  

    char currentPlayer = 'X';
    int row, col;
 
    for (int turn = 1; turn <= SIZE * SIZE; turn++) { 
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Validate input
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            turn--; 
            continue;
        }
        if(board[row][col] == ' ')
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