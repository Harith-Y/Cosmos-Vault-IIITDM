#include <iostream>

using namespace std;

class SquarePackage {
    private: 
        int matrix[10][10];
        int size;

        int rowSum(int ) const;
        int colSum(int ) const;
        int diagSum(bool) const;

    public: 
        SquarePackage(int , int matrix[10][10]);
        ~SquarePackage();
        bool isMagicSquare() const;
};

void latinSquare(int lat[100][100], int n);
