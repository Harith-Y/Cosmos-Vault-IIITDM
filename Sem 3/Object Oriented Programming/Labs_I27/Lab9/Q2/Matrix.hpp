#include <iostream>

using namespace std;

#define MAX_SIZE 10

class Matrix {
    private: 
        int rows;
        int cols;
        int data[MAX_SIZE][MAX_SIZE];

    public:
        Matrix();
        ~Matrix();

        Matrix(int, int);

        Matrix(const Matrix&);

        Matrix& operator = (const Matrix&);
        Matrix operator + (const Matrix&);
        Matrix operator - (const Matrix&);
        Matrix operator * (const Matrix&);

        int* operator [] (int i);

        friend ostream& operator << (ostream& out, const Matrix& mat);
        friend istream& operator >> (istream& in, Matrix& mat);

        Matrix& operator ++ (); // Prefix increment: ++A
        Matrix operator ++ (int); // Postfix increment: A++
        Matrix& operator -- (); // Prefix decrement: --A
        Matrix operator -- (int); // Postfix decrement: A--
};
