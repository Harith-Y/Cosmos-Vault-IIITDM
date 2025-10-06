#include "TicTacToe.hpp"

void TicTacToe :: displayBoard() {
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];

            if (j < 2)
                cout << " |";
        }

        cout << endl;

        if (i < 2) 
            cout << "---|---|---" << endl;
    }
    cout << endl;
}

void TicTacToe :: resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) 
            board[i][j] = ' ';

    currentPlayer = 'X';  // Start with player 'X'
}

bool TicTacToe :: isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;

    return true;
}
