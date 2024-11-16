#include <iostream>

class SquarePackage {
private: int matrix[10][10];
private: int size;

private: int rowSum(int row) const;
private: int colSum(int col) const;
private: int diagSum(bool mainDiagonal) const;

public: SquarePackage(int size, int matrix[10][10]);
public: ~SquarePackage();
public: bool isMagicSquare() const;
};

void latinSquare(int lat[100][100], int n);
