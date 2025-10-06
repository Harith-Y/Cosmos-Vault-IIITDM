#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
#define MAX_MATRICES 100
#define INFINITY_SUBSTITUTE 1000000000  // A very large number to represent "infinity"

// Function to print the optimal parenthesization
void printOptimalParenthesis(int s[][MAX_MATRICES], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Main function to solve the Matrix Chain Multiplication problem
void matrixChainMultiplication(int p[], int n) {
    int m[MAX_MATRICES][MAX_MATRICES] = {0};  // Stores the minimum number of multiplications
    int s[MAX_MATRICES][MAX_MATRICES] = {0};  // Stores the splitting points
    int i, j, k, L, q;

    // L is the chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INFINITY_SUBSTITUTE;  // Initialize with our "infinity" substitute

            // Try all possible splitting points between i and j
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                // If we found a better solution, update m[i][j] and s[i][j]
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the results
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(s, 1, n - 1);
    printf("\n");
}

int main() {
    int p[MAX_MATRICES];  // Array to store matrix dimensions
    int n;  // Number of matrices
    
    // Get the number of matrices from the user
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_MATRICES - 1) {
        printf("Invalid number of matrices. Please enter a number between 1 and %d.\n", MAX_MATRICES - 1);
        return 1;
    }
    
    // Get the dimensions from the user
    printf("Enter %d dimensions:\n", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
        
        if (p[i] <= 0) {
            printf("Invalid dimension. Please enter positive integers only.\n");
            return 1;
        }
    }
    
    // Print the input dimensions
    printf("Matrix dimensions: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Call the main function
    matrixChainMultiplication(p, n + 1);

    return 0;
}