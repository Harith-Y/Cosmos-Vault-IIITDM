#include <stdio.h>
#include "matrix.h"

struct matrix matrixSubtract(struct matrix a, struct matrix b)
{
    struct matrix result;

    if ((a.rows != b.rows) || (a.cols != b.cols))
    {
        printf("Error: Matrices must have the same dimensions.\n");
        result.rows = 0;
        result.cols = 0;
        return result;
    }

    result.rows = a.rows;
    result.cols = a.cols;

    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[i][j] = a.data[i][j] - b.data[i][j];

    return result;
}
