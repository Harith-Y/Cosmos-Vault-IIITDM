#include "Matrix.hpp"

void Matrix :: freeMatrix() {
    for (int i = 0; i < rows; i++)
        free(mat[i]);

    free(&rows);
    free(&cols);
}
