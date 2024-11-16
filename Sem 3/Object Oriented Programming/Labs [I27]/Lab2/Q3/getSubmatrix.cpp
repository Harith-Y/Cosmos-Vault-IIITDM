#include "matrix.h"

Matrix Matrix :: getSubmatrix(int c_row, int c_col)
{
    Matrix subMatrix = allocateMem(rows - 1, cols - 1);

    // cout << "rows is " << subMatrix.rows << "cols is " << subMatrix.cols << endl; 

    int r = 0, c = 0;

    for(int i = 0; i < rows; i++)
    {
        if(i == c_row)
        {
            continue;
        }

        c = 0;

        for(int j = 0; j < cols; j++)
        {
            if(j == c_col)
            {
                continue;
            }

            subMatrix.mat[r][c] = mat[i][j];
            // cout << subMatrix.mat[r][c] << " ";

            c++;
        }

        // cout << endl;

        r++;
    }

    return subMatrix;
}