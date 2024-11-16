#include "matrix.h"

Matrix Matrix :: allocateMem(int row, int col)
{
    Matrix m;

    m.rows = row;
    m.cols = col;
    m.mat = (double**)malloc(row * sizeof(double*));
    
    if(m.mat == NULL)
    {
        free(m.mat);
        cout << "Memory allocation failed" << endl;
        return m;
    }

    for(int i = 0; i < row; i++)
    {
        m.mat[i] = (double*)calloc(col, sizeof(double));

        if(m.mat[i] == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                free(m.mat[j]);
            }

            free(m.mat);
            free(m.mat);
            cout << "Memory allocation failed" << endl;
            return m;
        }
    }

    return m;
}