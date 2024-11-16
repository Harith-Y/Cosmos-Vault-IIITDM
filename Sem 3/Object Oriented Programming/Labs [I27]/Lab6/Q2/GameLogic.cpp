// #include <iostream>
#include "TicTacToe.hpp"

using namespace std;

void TicTacToe :: playGame() {
    cout << "Select mode: (1) Player vs Player, (2) Player vs System, (3) System vs System: ";
    cin >> mode;

    resetBoard();
    displayBoard();

    while (true) {
        if (mode == 1) { // Player vs Player
            int row, column;
            cout << "Player " << currentPlayer << "'s turn." << endl;
            cout << "Enter row (0-2): ";
            cin >> row;
            cout << "Enter column (0-2): ";
            cin >> column;

            if (makeMove(row, column)) {
                displayBoard();
                if (isWinner(currentPlayer)) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                } 
                
                else if (isBoardFull()) {
                    cout << "It's a draw!" << endl;
                    break;
                }
                switchPlayer();  // Switch to next player
            } 
            
            else
                cout << "Invalid move. Try again." << endl;
        } 
        
        else if (mode == 2) { // Player vs System
            if (currentPlayer == 'X') { // Player's turn
                int row, column;
                cout << "Player " << currentPlayer << "'s turn." << endl;
                cout << "Enter row (0-2): ";
                cin >> row;
                cout << "Enter column (0-2): ";
                cin >> column;

                if (makeMove(row, column)) {
                    displayBoard();
                    if (isWinner(currentPlayer)) {
                        cout << "Player " << currentPlayer << " wins!" << endl;
                        break;
                    } 
                    
                    else if (isBoardFull()) {
                        cout << "It's a draw!" << endl;
                        break;
                    }

                    switchPlayer();  // Switch to System
                } 
                
                else
                    cout << "Invalid move. Try again." << endl;
            } 
            
            else { // System's turn
                autoMove(); // Let the system play automatically
                displayBoard();
                if (isWinner(currentPlayer)) {
                    cout << "System (Player O) wins!" << endl;
                    break;
                } 
                
                else if (isBoardFull()) {
                    cout << "It's a draw!" << endl;
                    break;
                }
                
                switchPlayer();
            }
        } 
        
        else if (mode == 3) { // System vs System
            autoMove();  // System's move
            displayBoard();
            if (isWinner(currentPlayer)) {
                cout << "System (Player " << currentPlayer << ") wins!" << endl;
                break;
            } 
            
            else if (isBoardFull()) {
                cout << "It's a draw!" << endl;
                break;
            }
            
            switchPlayer();
        }
    }

    if (playAgain())
        playGame();  // Restart the game
    else
        cout << "Thanks for playing!" << endl;
}
