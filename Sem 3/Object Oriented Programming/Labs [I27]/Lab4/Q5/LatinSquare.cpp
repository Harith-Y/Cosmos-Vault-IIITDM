#include "SquarePackage.hpp"
#include <iostream>

using namespace std;

void latinSquare(int lat[100][100], int n) {
    for (int i = 0; i < n; i++) {
        int a = 0;

        for (int j = i + 1; j <= n; j++)
            lat[i][a++] = j;

        for (int k = 1; k <= i; k++)
            lat[i][a++] = k;
    }
}
