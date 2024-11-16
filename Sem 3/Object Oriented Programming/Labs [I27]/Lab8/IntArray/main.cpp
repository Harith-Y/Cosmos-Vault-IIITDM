#include "IntArray.hpp"

int main() {
    IntArray A1(5);
    IntArray A2;
    cin >> A1;
    cout << A1 << endl;
    A2 = A1;
    cout << A2;
    return 0;
}