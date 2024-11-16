#include <iostream>
#include "SquarePackage.hpp"

using namespace std;

int main() {
    int choice;
    cout << "Enter 1 to check a magic square, 2 to generate a Latin square: ";
    cin >> choice;

    if (choice == 1) {
        int size;
        cout << "Enter the size of the square matrix: ";
        cin >> size;

        if ((size <= 0) || (size > 10)) {
            cout << "Invalid size! Please enter a size between 1 and 10." << endl;
            return 1;
        }

        int matrix[10][10];
        cout << "Enter the elements of the square matrix (row by row):" << endl;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cin >> matrix[i][j];

        SquarePackage square(size, matrix);

        if (square.isMagicSquare()) {
            cout << "The square is a magic square." << endl;
        } else {
            cout << "The square is not a magic square." << endl;
        }
    } 
    else if (choice == 2) {
        int n;
        cout << "Enter the size of the Latin square (up to 100): ";
        cin >> n;

        if (n <= 0 || n > 100) {
            cout << "Error! Please enter a size between 1 and 100." << endl;
            return 1;
        }

        int lat[100][100];
        latinSquare(lat, n);

        cout << "Latin square:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << lat[i][j] << " ";

            cout << endl;
        }
    } 
    else 
        cout << "Please enter a valid choice!" << endl;

    return 0;
}
