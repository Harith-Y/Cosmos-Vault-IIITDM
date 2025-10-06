#include "Matrix.hpp"

int main() {
    
    Matrix A(2, 2);
    cin >> A;
    
    cout << "Original Matrix A:\n" << A;

    cout << "Post-increment A++:\n";
    Matrix B = A++;
    cout << "Matrix A after A++:\n" << A;
    cout << "Matrix B (original A):\n" << B;

    cout << "Pre-increment ++A:\n";
    cout << ++A;

    cout << "Post-decrement A--:\n";
    B = A--;
    cout << "Matrix A after A--:\n" << A;
    cout << "Matrix B (original A):\n" << B;

    cout << "Pre-decrement --A:\n";
    cout << --A;

    return 0;
}
