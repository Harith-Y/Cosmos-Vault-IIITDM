#include "Matrix.hpp"

int main() {
    Matrix A, B, C;
    
    cin >> A;
    cin >> B;

    cout << "Matrix A: \n" << A;
    cout << "Matrix B: \n" << B;

    C = A + B;
    cout << "A + B: \n" << C;

    C = A - B;
    cout << "A - B: \n" << C;

    C = A * B;
    cout << "A * B: \n" << C;

    return 0;
}
