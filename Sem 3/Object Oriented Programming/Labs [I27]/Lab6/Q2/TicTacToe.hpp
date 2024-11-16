#include <iostream>
#include <cstdlib>

class TicTacToe {

    private: char board[3][3]; // Tic Tac Toe board
    private: char currentPlayer; // 'X' or 'O'
    private: int mode; // Game mode (1 = PvP, 2 = PvS, 3 = SvS)


    public: TicTacToe();
    public: ~TicTacToe();
    
    public: void displayBoard();
    public: void resetBoard();
    public: bool isBoardFull();
    public: bool makeMove(int, int);
    public : char getCurrentPlayer();
    public: void switchPlayer();
    public: bool isWinner(char);
    public: bool playAgain();
    public: void playGame();

    void autoMove(); // For System involved moves
.