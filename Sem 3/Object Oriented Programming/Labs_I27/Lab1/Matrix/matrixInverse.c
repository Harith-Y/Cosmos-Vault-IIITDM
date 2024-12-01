#include "matrix.h"

struct matrix matrixInverse(struct matrix a) {
    struct matrix result;
    int det = matrixDeterminant(a);

    if ((a.rows != 2) || (a.cols != 2) || (a.rows != 3) || (a.cols != 3)) {
        printf("Error! Inverse can only be calculated for 2x2 or 3x3 matrices.\n");
        result.rows = 0;
        result.cols = 0;
        return result;
    }

    if (det == 0) {
        printf("Error! Matrix is singular and cannot have an inverse.\n");
        result.rows = 0;
        result.cols = 0;
        return result;
    }

    if ((a.rows == 2) || (a.cols == 2)) {
        result.rows = 2;
        result.cols = 2;

        result.data[0][0] = a.data[1][1];
        result.data[0][1] = -a.data[0][1];
        result.data[1][0] = -a.data[1][0];
        result.data[1][1] = a.data[0][0];

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] /= det;

        return result;
    }

    else if ((a.rows == 3) || (a.cols == 3)) {

        result.data[0][0] = (a.data[1][1] * a.data[2][2] - a.data[1][2] * a.data[2][1]);
        result.data[0][1] = -(a.data[1][0] * a.data[2][2] - a.data[1][2] * a.data[2][0]);
        result.data[0][2] = (a.data[1][0] * a.data[2][1] - a.data[1][1] * a.data[2][0]);

        result.data[1][0] = -(a.data[0][1] * a.data[2][2] - a.data[0][2] * a.data[2][1]);
        result.data[1][1] = (a.data[0][0] * a.data[2][2] - a.data[0][2] * a.data[2][0]);
        result.data[1][2] = -(a.data[0][0] * a.data[2][1] - a.data[0][1] * a.data[2][0]);

        result.data[2][0] = (a.data[0][1] * a.data[1][2] - a.data[0][2] * a.data[1][1]);
        result.data[2][1] = -(a.data[0][0] * a.data[1][2] - a.data[0][2] * a.data[1][0]);
        result.data[2][2] = (a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0]);

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                result.data[i][j] /= det;

        return result;
    }
}