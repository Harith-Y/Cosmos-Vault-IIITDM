#include "SquarePackage.hpp"

int SquarePackage :: rowSum(int row) const {
    int sum = 0;
    for (int j = 0; j < size; j++)
        sum += matrix[row][j];

    return sum;
}