#include <iostream>
using namespace std;

class Matrix
{
    private: int rows;
    private: int cols;
    private: double** mat;


    public: void createMatrix();
    public: void displayMatrix();
    public: Matrix transMatrix();
    public: void freeMatrix();
    public: double detMatrix();
    public: Matrix allocateMem(int row, int col);
    public: Matrix getSubmatrix(int c_row, int c_col);
    public: Matrix invMatrix();
    public: Matrix addMatrix(const Matrix &m);
    public: Matrix subMatrix(const Matrix &m);
    public: Matrix mulMatrix(const Matrix &m);
    public: double coFactor(int c_row, int c_col);
        
};

