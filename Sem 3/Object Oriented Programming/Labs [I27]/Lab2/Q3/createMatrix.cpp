#include "Matrix.hpp"

void Matrix :: createMatrix() {
    int r, c;
    cout << "Enter the Number of rows and Number of cols" << endl;
    cin >> r >> c;
    rows = r;
    cols = c;

    mat = (double**)calloc(rows, sizeof(double*));
    if(mat == NULL)
        cout << "Memory Allocation failed";
    
    for(int i = 0; i < rows; i++) {
        mat[i] = (double*)calloc(cols, sizeof(double));

        if(mat[i] == NULL) {
            for(int j = 0; j < i; j++)
                free(mat[j]);
            
            free(mat);
            cout << "Memory Allocation failed";
        }

        for(int j = 0; j < cols; j++)
            cin >> mat[i][j];
    }
}