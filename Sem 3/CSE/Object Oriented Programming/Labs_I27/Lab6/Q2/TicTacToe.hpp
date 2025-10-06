#include <iostream>
#include <cstdlib>

using namespace std;

class TicTacToe {

    private: 
        char board[3][3]; // Tic Tac Toe board
        char currentPlayer; // 'X' or 'O'
        int mode; // Game mode (1 = PvP, 2 = PvS, 3 = SvS)

    public:
        TicTacToe();
        ~TicTacToe();
    
        void displayBoard();
        void resetBoard();
        bool isBoardFull();
        bool makeMove(int, int);
        char getCurrentPlayer();
        void switchPlayer();
        bool isWinner(char);
        bool playAgain();
        void playGame();

        void autoMove(); // For System involved moves
};
