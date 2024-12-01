#include "matrix.h"

struct matrix matrixMultiply(struct matrix a, struct matrix b) {
    struct matrix result;

    if (a.cols != b.rows) {
        printf("Error! Number of columns in matrix A must equal number of rows in matrix B.\n");
        result.rows = 0;
        result.cols = 0;
        return result;
    }

    result.rows = a.rows;
    result.cols = b.cols;

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
        }
    }

    return result;
}
