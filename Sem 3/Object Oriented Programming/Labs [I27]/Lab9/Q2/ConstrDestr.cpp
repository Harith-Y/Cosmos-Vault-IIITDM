#include "Matrix.hpp"

Matrix :: Matrix() : rows(0), cols(0) {}

// Matrix :: Matrix(int r, int c) : rows(0), cols(0) {
//     if (r > MAX_SIZE || c > MAX_SIZE) {
//         cout << "Matrix dimensions exceed MAX_SIZE." << endl;
//     } else {
//         rows = r;
//         cols = c;
//     }
// }

Matrix :: Matrix(int r, int c) : rows(r), cols(c) {
    if ((r > MAX_SIZE) || (c > MAX_SIZE)) {
        cout << "Matrix dimensions exceed MAX_SIZE." << endl;
        rows = 0;
        cols = 0;
    } 
    
    else {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
    }
}

Matrix :: Matrix(const Matrix& mat) : rows(mat.rows), cols(mat.cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = mat.data[i][j];
}

Matrix :: ~Matrix() {
    cout << "Destructor function called" << endl;
}
