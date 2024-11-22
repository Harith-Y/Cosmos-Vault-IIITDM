#include "Matrix.hpp"

Matrix Matrix :: addMatrix(const Matrix &m) {
    if ((rows != m.rows) || (cols != m.cols)) {
        cout << "Matrices must have the same dimensions to add!" << endl;
        return allocateMem(0, 0);
    }

    Matrix result = allocateMem(rows, cols);

    if (result.mat == NULL) {
        cout << "Memory Allocation failed" << endl;
        return result;
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.mat[i][j] = mat[i][j] + m.mat[i][j];

    return result;
}
