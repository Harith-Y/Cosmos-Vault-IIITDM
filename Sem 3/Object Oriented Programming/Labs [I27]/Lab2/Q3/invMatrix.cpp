#include "matrix.h"
#include <cmath>

double Matrix :: coFactor(int c_row, int c_col)
{
    Matrix subMatrix = getSubmatrix(c_row, c_col);

    double c_cof = ((c_row + c_col) % 2 == 0 ? 1 : -1) * subMatrix.detMatrix();

    subMatrix.freeMatrix();

    return c_cof;
}

Matrix Matrix :: invMatrix()
{
    if(mat == NULL || rows != cols)
    {
        cout << "Inverse cant be found!" << endl;
    }

    else
    {
        double det = detMatrix();

        if(det < 0.0000000001 && det >= 0)
        {
            cout << "Determinant too small!" << endl;
        }

        else
        {
            Matrix cofactor = allocateMem(rows, cols);

            if(cofactor.mat == NULL)
            {
                cout << "Memory allocation failed!" << endl;
            }

            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    cofactor.mat[i][j] = coFactor(i,j);
                    // cout << cofactor.mat[i][j] << " ";
                }
                
                // cout << endl;
            }

            Matrix adjoint = cofactor.transMatrix();

            cofactor.freeMatrix();

            if(adjoint.mat == NULL)
            {
                cout << "Memory allocation failed" << endl;
            }

            for(int i = 0; i < adjoint.rows; i++)
            {
                for(int j = 0; j < adjoint.cols; j++)
                {
                    adjoint.mat[i][j] = (adjoint.mat[i][j] / det);
                }
            }

            return adjoint;
        }
        
    }
    
}