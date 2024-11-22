#include <iostream>

using namespace std;

#define MAX_SIZE 10

class Matrix {
    private:
        int rows;
        int cols;
        int data[MAX_SIZE][MAX_SIZE];

    public:
        Matrix() : rows(0), cols(0) {}
        ~Matrix();

        Matrix(int, int);

        Matrix(const Matrix&);

        Matrix & operator = (const Matrix&);
        Matrix operator + (const Matrix&);
        Matrix operator - (const Matrix&);
        Matrix operator * (const Matrix&);

        int* operator[] (int i);

        friend ostream & operator << (ostream& , const Matrix& );
        friend istream & operator >> (istream& , Matrix& );
};
