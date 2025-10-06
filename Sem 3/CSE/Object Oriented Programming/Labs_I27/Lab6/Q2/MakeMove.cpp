#include "TicTacToe.hpp"

bool TicTacToe :: makeMove(int row, int column) {
    if ((row >= 0) && (row < 3) && (column >= 0) && (column < 3) && (board[row][column] == ' ')) {
        board[row][column] = currentPlayer;
        return true;
    }
    return false;
}
