#include "SquarePackage.hpp"

SquarePackage :: SquarePackage(int n, int mat[10][10]) {
    size = n;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = mat[i][j];
}

SquarePackage :: ~SquarePackage() {
    // Destructor logic
}
