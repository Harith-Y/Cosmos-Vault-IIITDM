#include "Matrix.hpp"

Matrix Matrix :: operator + (const Matrix& mat) {
    if ((rows != mat.rows) || (cols != mat.cols)) {
        cout << "Matrices must have the same dimensions for addition." << endl;
        return Matrix();
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] + mat.data[i][j];

    return result;
}

Matrix Matrix :: operator - (const Matrix& mat) {
    if ((rows != mat.rows) || (cols != mat.cols)) {
        cout << "Matrices must have the same dimensions for subtraction." << endl;
        return Matrix();
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] - mat.data[i][j];

    return result;
}

Matrix Matrix :: operator * (const Matrix& mat) {
    if (cols != mat.rows) {
        cout << "Matrix A's columns must match Matrix B's rows for multiplication." << endl;
        return Matrix();
    }

    Matrix result(rows, mat.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            result.data[i][j] = 0;

            for (int k = 0; k < cols; k++)
                result.data[i][j] += data[i][k] * mat.data[k][j];
        }
    }

    return result;
}



ostream & operator << (ostream& o, const Matrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) 
            o << mat.data[i][j] << " ";

        o << endl;
    }

    return o;
}

istream & operator >> (istream& in, Matrix& mat) {
    cout << "Enter number of rows and columns: ";
    in >> mat.rows >> mat.cols;
    if ((mat.rows > MAX_SIZE) || (mat.cols > MAX_SIZE)) {
        cout << "Matrix dimensions exceed MAX_SIZE." << endl;
        return in;
    }

    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < mat.rows; i++)
        for (int j = 0; j < mat.cols; j++)
            in >> mat.data[i][j];

    return in;
}
