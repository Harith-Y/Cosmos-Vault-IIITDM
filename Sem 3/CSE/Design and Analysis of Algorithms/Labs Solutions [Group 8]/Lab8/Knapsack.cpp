#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//max function
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int** K = new int*[n + 1];  // 2D DP table //we're using dynamic mem allocation to prevent segementation error thrown by the rather large	 	values of W
    for (int i = 0; i <= n; ++i) {
        K[i] = new int[W + 1];
    }

    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int result = K[n][W];

    // Clean up dynamically allocated memory
    for (int i = 0; i <= n; ++i) {
        delete[] K[i];
    }
    delete[] K;

    return result;
}

int main() {
    ifstream inputFile("s2000.kp");
    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string line;
    int n, W;

    // Read n and W
    getline(inputFile, line);
    n = stoi(line);
    getline(inputFile, line);
    W = stoi(line);

    // Ensure n is valid before declaring arrays
    if (n <= 0 || W <= 0) {
        cerr << "Invalid values for n or W!" << endl;
        return 1;
    }

    // Use dynamic allocation for arrays
    int* val = new int[n];
    int* wt = new int[n];

    // Read values and weights
    for (int i = 0; i < n; i++)
        inputFile >> val[i] >> wt[i];

    inputFile.close();

    printf("Maximum value in knapsack = %d\n", knapsack(W, wt, val, n));

    // Clean up dynamically allocated arrays
    delete[] val;
    delete[] wt;

    return 0;
}

