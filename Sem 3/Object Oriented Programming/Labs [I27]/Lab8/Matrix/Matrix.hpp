#include <iostream>

using namespace std;

#define MAX_SIZE 10

class Matrix {
    private: int rows;
    private: int cols;
    private: int data[MAX_SIZE][MAX_SIZE];


    public: Matrix();
    public: ~Matrix();

    public: Matrix(int, int);

    public: Matrix(const Matrix&);

    public: Matrix& operator=(const Matrix&);
    public: Matrix operator+(const Matrix&);
    public: Matrix operator-(const Matrix&);
    public: Matrix operator*(const Matrix&);

    public: int* operator[](int i);

    public: friend ostream& operator<<(ostream& out, const Matrix& mat);
    public: friend istream& operator>>(istream& in, Matrix& mat);
};
