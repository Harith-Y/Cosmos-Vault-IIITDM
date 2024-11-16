#include "matrix.h"

Matrix Matrix :: transMatrix()
{
    cout << endl;

    if(mat == NULL)
    {
        cout << "Cant do transposition!" << endl;
    }

    else
    {
        Matrix trans = allocateMem(cols, rows);

        if (trans.mat == NULL)
        {
            cout << "Memory Allocation failed" << endl;
            return trans;
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                trans.mat[j][i] = mat[i][j];
            }
        }

        return trans;
    }
}