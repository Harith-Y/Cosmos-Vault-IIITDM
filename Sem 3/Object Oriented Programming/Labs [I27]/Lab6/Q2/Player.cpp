#include "TicTacToe.hpp"

using namespace std;

// Get the current player ('X' or 'O')
char TicTacToe::getCurrentPlayer() {
    return currentPlayer;
}

// Switch to the next player
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
