#include "Matrix.hpp"

double Matrix :: detMatrix() {
    if(mat == NULL || rows != cols)
        cout << "Determinant cant be found!" << endl;
    else {
        if(rows == 1)
            return mat[0][0];

        if(rows == 2)
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        double det = 0;
        int sign = 1;

        for(int j = 0; j < cols; j++) {
            Matrix subMatrix = getSubmatrix(0, j);
            //cout << "subMatrix rows is: " << subMatrix.rows << " cols is: " << subMatrix.cols << endl;

            det += sign * mat[0][j] * subMatrix.detMatrix();

            subMatrix.freeMatrix();

            sign *= -1;
        }
        
        return det;
    }   
}