#include "TicTacToe.hpp"

bool TicTacToe :: playAgain() {
    char choice;

    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;

    return ((choice == 'Y') || (choice == 'y'));
}
