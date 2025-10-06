#include "SquarePackage.hpp"

int SquarePackage :: colSum(int col) const {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += matrix[i][col];

    return sum;
}
