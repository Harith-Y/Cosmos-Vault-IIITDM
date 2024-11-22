#include <iostream>

using namespace std;

class Matrix {
    private: 
        int rows;
        int cols;
        double** mat;

    public:
        void createMatrix();
        void displayMatrix();
        Matrix transMatrix();
        void freeMatrix();
        double detMatrix();
        Matrix allocateMem(int , int );
        Matrix getSubmatrix(int , int );
        Matrix invMatrix();
        Matrix addMatrix(const Matrix &);
        Matrix subMatrix(const Matrix &);
        Matrix mulMatrix(const Matrix &);
        double coFactor(int , int );
        
};
