#include "SquarePackage.hpp"

int SquarePackage :: diagSum(bool mainDiagonal) const {
    int sum = 0;
    
    if (mainDiagonal) {
        for (int i = 0; i < size; ++i)
            sum += matrix[i][i];
    } 
    
    else {
        for (int i = 0; i < size; ++i)
            sum += matrix[i][size - i - 1];
    }
    return sum;
}