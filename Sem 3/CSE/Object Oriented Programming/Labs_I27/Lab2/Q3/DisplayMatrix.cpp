#include "Matrix.hpp"

void Matrix :: displayMatrix() {
    cout << endl << "The given matrix is: " << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
        
        cout << endl;
    }
}
