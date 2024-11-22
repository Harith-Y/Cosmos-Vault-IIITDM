#include "TicTacToe.hpp"

void TicTacToe::autoMove() {
    int row, column;

    do {
        row = rand() % 3;
        column = rand() % 3;
    } 
    while (!makeMove(row, column));

    cout << "System (Player " << currentPlayer << ") makes a move at (" << row << ", " << column << ")" << endl;
}
