#include "Matrix.hpp"

int main() {
    int flag = 1, choice;
    while(flag) {
        cout << "What do you want to do: \n 1. Add Matrices \n 2. Subtract Matrices \n 3. Multiply Matrices \n 4. Find Transpose \n 5. Find Determinant \n 6. Find Inverse \n 7. Exit \n";
        cin >> choice;
        switch(choice) {
            case 1:   
                Matrix m1, m2, m3;
                m1.createMatrix();
                m2.createMatrix();
                m3 = m1.addMatrix(m2);
                m3.displayMatrix();
                m1.freeMatrix();
                m2.freeMatrix();
                m3.freeMatrix();
                break;
            case 2:
                Matrix m1, m2, m3;
                m1.createMatrix();
                m2.createMatrix();
                m3 = m1.subMatrix(m2);
                m3.displayMatrix();
                m1.freeMatrix();
                m2.freeMatrix();
                m3.freeMatrix();
                break;
            case 3:
                Matrix m1, m2, m3;
                m1.createMatrix();
                m2.createMatrix();
                m3 = m1.mulMatrix(m2);
                m3.displayMatrix();
                m1.freeMatrix();
                m2.freeMatrix();
                m3.freeMatrix();
                break;
            case 4:
                Matrix m1, m2;
                m1.createMatrix();
                m2 = m1.transMatrix();
                m2.displayMatrix();
                m1.freeMatrix();
                m2.freeMatrix();
                break;
            case 5:
                Matrix m1, m2;
                m1.createMatrix();
                cout << "Determinant is: " << m1.detMatrix() << endl;
                m1.freeMatrix();
                break;
            case 6:
                Matrix m1, m2;
                m1.createMatrix();
                m2 = m1.invMatrix();
                m2.displayMatrix();
                m1.freeMatrix();
                m2.freeMatrix();
                break;
            case 7:
                flag = 0;
                break;
            default:
                cout << "Enter proper value!" << endl;
        }
    }
    cout << "Exiting..." << endl;
    return 0;
}
