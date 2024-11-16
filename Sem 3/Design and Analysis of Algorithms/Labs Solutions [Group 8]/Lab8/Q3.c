#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) // helper function to find max of the L indices
{
    return (a > b) ? a : b;
}

void LCS(char X[], char Y[], int M, int N) 
{
    int **L = (int **)malloc((M + 1) * sizeof(int *)); // We do M + 1 because the first row will only have 0 (NULL elements)
    for (int i = 0; i <= M; i++) 
    {
        L[i] = (int *)malloc((N + 1) * sizeof(int)); // We do N + 1 because the first column will only have 0 (NULL elements)
    }

    for (int i = 0; i <= M; i++) 
    {
        for (int j = 0; j <= N; j++) 
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0; // For the reason mentioned before, first row and column entries will be 0
            }
            else if (X[i-1] == Y[j-1])
            {
                L[i][j] = L[i-1][j-1] + 1; // if there exists an equal entry as we traverse along the strings, make this change - the current problem is 1 + the optimal solution of previous problem
            }
            else
            {
                L[i][j] = max(L[i-1][j], L[i][j-1]); // if they arent equal, do this - the max size must be in L[i - 1][j] or L[i][j - 1] only (they are the probable optimal solutions of previous problem)
            }

        }
    }

    int length = L[M][N];
    printf("The length of the Longest Common Subsequence is: %d\n", length); // finally the L[M][N] 'th entry is the size of LCS - its the final problem that was solved for the entire array - hence the answer

    char *lcs = (char *)malloc((length + 1) * sizeof(char));
    lcs[length] = '\0';  

    int i = M, j = N, index = length - 1;
    while (i > 0 && j > 0) 
    {
        if (X[i-1] == Y[j-1]) // if the characters are equal, add it to the lcs
        {
            lcs[index] = X[i-1];
            i--; j--; index--; // go diagonally back - to the previous subproblem. we start from length - 1 because the subsequence is found in reverse
        }
        else if (L[i-1][j] > L[i][j-1]) // if the characters arent equal and the i-1, j solution is better than the i, j-1 one,  go to i - 1 and repeat the while loop process
        {
            i--; 
        }

        else // if the characters arent equal and the i, j - 1 solution is better than the i - 1, j one,  go to j - 1 and repeat the while loop process
        {
            j--;
        }

    }

    printf("The Longest Common Subsequence is: %s\n", lcs);

    for (int i = 0; i <= M; i++)
        free(L[i]);
    free(L);
    free(lcs);
}

int main() 
{
    int M, N;
    printf("Enter the sizes of the 2 arrays: ");
    scanf("%d %d", &M, &N);

    char *X = (char *)malloc((M + 1) * sizeof(char));
    char *Y = (char *)malloc((N + 1) * sizeof(char));

    if (X == NULL || Y == NULL) 
    {
        printf("Memory allocation failed.\n");
        free(X);
        free(Y);
        return 1;
    }

    printf("Enter %d characters for first array:\n", M);
    for (int i = 0; i < M; i++) 
    {
        scanf(" %c", &X[i]);
    }
    X[M] = '\0';

    printf("Enter %d characters for second array:\n", N);
    for (int i = 0; i < N; i++) 
    {
        scanf(" %c", &Y[i]);
    }
    Y[N] = '\0';

    LCS(X, Y, M, N);

    free(X);
    free(Y);
    return 0;
}