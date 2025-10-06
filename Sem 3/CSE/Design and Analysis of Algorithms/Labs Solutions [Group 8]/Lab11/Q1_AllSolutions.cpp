// Time Complexity: O(N!)   
#include <iostream>
using namespace std;

// Check if the current position is safe to place a queen
bool isSafe(int** board, int N, int row, int col) {
    // Check columns on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueens(int** board, int N, int col, int& count) {
    // Base case: If all queens are placed, increment the count
    if (col >= N) {
        count++;

        // Print the solutions i.e. Instances of the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        return;
    }

    // Place queens in all possible rows
    for (int i = 0; i < N; i++) {
        if (isSafe(board, N, i, col)) { // Check if the current position is safe to place a queen
            board[i][col] = 1; // Place the queen
            solveNQueens(board, N, col + 1, count); // Recur for the next column
            board[i][col] = 0; // Backtrack: Remove the queen
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    // Initialize the board with N x N grid filled with 0s
    int** board = new int*[N];
    for (int i = 0; i < N; i++) {
        board[i] = new int[N];

        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }
    // Print the initial state of the board
    if (N > 0) {
        cout << "Initial state of the board:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    
    // Initialize the count of solutions to 0
    int count = 0;

    if (N >= 4)
        cout << "Solution(s) to the given N-Queens Problem:" << endl;
    else if (N == 1)
        cout << "Solution to the given N-Queens Problem:" << endl;
    else
        cout << "No solution exists for the given N-Queens Problem." << endl;

    solveNQueens(board, N, 0, count);
    
    if (N > 0)
        cout << "Number of solutions: " << count << endl;


    // Free the allocated memory
    for (int i = 0; i < N; i++)
        delete[] board[i];

    delete[] board;
    return 0;
}
