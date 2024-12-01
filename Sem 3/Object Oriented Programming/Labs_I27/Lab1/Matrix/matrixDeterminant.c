#include "matrix.h"

int matrixDeterminant(struct matrix a) {
    if (a.rows != a.cols) {
        printf("Error! Determinant can only be calculated for square matrices.\n");
        return 0;
    }

    if (a.rows == 1)
        return a.data[0][0];

    else if (a.rows == 2)
        return a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];

    else {
        int determinant = 0;
        for (int i = 0; i < a.cols; i++) {
            struct matrix submatrix;
            submatrix.rows = a.rows - 1;
            submatrix.cols = a.cols - 1;

            for (int m = 1; m < a.rows; m++) {
                int z = 0;
                for (int n = 0; n < a.cols; n++) {
                    if (n == i)
                        continue;

                    submatrix.data[m - 1][z] = a.data[m][n];
                    z++;
                }
            }
            determinant += a.data[0][i] * matrixDeterminant(submatrix) * (i % 2 == 0 ? 1 : -1);
        }
        return determinant;
    }
}
