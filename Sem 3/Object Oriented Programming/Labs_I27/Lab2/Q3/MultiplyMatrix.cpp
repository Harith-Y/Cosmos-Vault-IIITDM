#include "Matrix.hpp"

Matrix Matrix::mulMatrix(const Matrix &m) {
    if (cols != m.rows) {
        cout << "Matrices dimensions are incompatible for multiplication!" << endl;
        return allocateMem(0, 0);
    }

    Matrix result = allocateMem(rows, m.cols);

    if (result.mat == NULL) {
        cout << "Memory Allocation failed" << endl;
        return result;
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < m.cols; j++) {
            result.mat[i][j] = 0;
            
            for (int k = 0; k < cols; k++)
                result.mat[i][j] += mat[i][k] * m.mat[k][j];
        }
    }

    return result;
}
