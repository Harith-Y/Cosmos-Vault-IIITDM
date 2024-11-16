#include <iostream>

using namespace std;


#define MAX_N 20 // max size for the N Queens table

// Helper function to check if any other queen can strike
bool isSafe(int board[][MAX_N], int row, int col, int n) {
	// Check strike in column
	for(int j = 0; j < col; j++) {
		if(board[row][j] == 1)
			return false;
	}
	
	// Check strike in diagonal left above
	for(int i = row, j = col; (i >=0 && j >= 0); i--, j--) {
		if(board[i][j] == 1)
			return false;
	}
	
	// Check strike in diagonal left below
	for(int i = row, j = col; (i < n && j >= 0); i++, j--) {
		if(board[i][j] == 1)
			return false;
	}
	
	return true;
}

// Backtrack function to find solution recursively
bool solveNQueens(int board[][MAX_N], int col, int n) {
	if(col >= n) // Col >=n means that the nth queen has been placed in the nth column, meaning the solution has been found - this serves as a terminating condition
		return true;


	for(int i = 0; i < n; i++) {
		if(isSafe(board, i, col, n)) { // Check if the particular row, col is SAFE
			board[i][col] = 1;
			
			if(solveNQueens(board, col + 1, n)) // If SAFE, check if successive solutions exist from this solution
				return true;
			
			board[i][col] = 0; // If successive solutions weren't found, the queen isn't in the right row for this column, hence mark it 0
		}
	}

	return false; // Post all the row, col iterations/ recursions for current solution, still if the function hasn't returned true, it means solution doesn't exist, hence return false
}

void printBoard(int board[][MAX_N], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] == 1)
				cout << "Q "; // Print Q if queen exists
			else
				cout << ". "; // Else empty
		}

		cout << endl;
	}
}

// Test Drive
int main() {
	int n;
	cout << "Enter the size of the Board (n x n): ";
	cin >> n;
	
	while((n <= 0) || (n > MAX_N)) {
		cout << "Invalid board size. Enter between 1 and " << MAX_N << endl;
		cin >> n;
	}
	
	int board[MAX_N][MAX_N] = {0};


	if(solveNQueens(board, 0, n)) {
		cout << "Solution exists. \n" << endl;
		printBoard(board, n);
	}

	else
		cout << "Solution doesn't exist for n = " << n << endl;
	
	return 0;
}
