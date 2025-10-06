#include "TicTacToe.hpp"

// Constructor to initialize the board and the current player
TicTacToe :: TicTacToe() {
    currentPlayer = 'X';
    resetBoard();
}

// Destructor
TicTacToe :: ~TicTacToe() {
    cout << "Game over!" << endl;
}
