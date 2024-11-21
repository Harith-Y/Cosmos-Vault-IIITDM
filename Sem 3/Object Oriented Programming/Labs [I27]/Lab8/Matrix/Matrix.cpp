#include "Matrix.hpp"

Matrix& Matrix :: operator = (const Matrix& mat) {
    if (this == &mat) 
        return *this;

    rows = mat.rows;
    cols = mat.cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = mat.data[i][j];

    return *this;
}

int* Matrix :: operator[] (int i) {
    if ((i >= rows) || (i < 0)) {
        cout << "Index out of bounds!" << endl;
        return nullptr;
    }

    return data[i];
}
