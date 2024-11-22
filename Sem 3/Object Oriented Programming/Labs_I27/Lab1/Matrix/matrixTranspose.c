#include <stdio.h>
#include "matrix.h"

struct matrix matrixTranspose(struct matrix a)
{
    struct matrix result;

    result.rows = a.cols;
    result.cols = a.rows;

    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            result.data[j][i] = a.data[i][j];

    return result;
}
