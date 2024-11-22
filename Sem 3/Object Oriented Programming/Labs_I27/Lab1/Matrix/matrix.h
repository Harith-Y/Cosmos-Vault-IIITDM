#define MATRIX_H

#define MAX_SIZE 10

struct matrix
{
  int rows;
  int cols;
  int data[MAX_SIZE][MAX_SIZE];
};

struct matrix matrixAdd(struct matrix a, struct matrix b);
struct matrix matrixSubtract(struct matrix a, struct matrix b);
struct matrix matrixMultiply(struct matrix a, struct matrix b);
struct matrix matrixTranspose(struct matrix a);
int matrixDeterminant(struct matrix a);
struct matrix matrixInverse(struct matrix a);
