#include "Matrix.hpp"

int main() {
    // Matrix A, B, C;
    
    // cin >> A;
    // cin >> B;

    // cout << "Matrix A: \n" << A;
    // cout << "Matrix B: \n" << B;

    // C = A + B;
    // cout << "A + B: \n" << C;

    // C = A - B;
    // cout << "A - B: \n" << C;

    // C = A * B;
    // cout << "A * B: \n" << C;

    // return 0;

    // Create two matrices with dimensions 2x2
    Matrix matrix1(2, 2);
    Matrix matrix2(2, 2);

    cout << "Enter values for matrix1 (2x2):\n";
    cin >> matrix1;

    cout << "Enter values for matrix2 (2x2):\n";
    cin >> matrix2;

    // Display the matrices
    cout << "Matrix 1:\n" << matrix1;
    cout << "Matrix 2:\n" << matrix2;

    // Test addition
    Matrix sum = matrix1 + matrix2;
    cout << "Sum of matrices:\n" << sum;

    // Test subtraction
    Matrix difference = matrix1 - matrix2;
    cout << "Difference of matrices:\n" << difference;

    // Test multiplication
    Matrix product = matrix1 * matrix2;
    cout << "Product of matrices:\n" << product;

    // Test assignment operator
    Matrix matrix3 = matrix1;
    cout << "Matrix 3 (assigned from matrix1):\n" << matrix3;

    // Test subscript operator
    cout << "Modifying the first element of matrix1...\n";
    matrix1[0][0] = 99;  // Modifies the first element of the first row
    cout << "Updated Matrix 1:\n" << matrix1;
}
