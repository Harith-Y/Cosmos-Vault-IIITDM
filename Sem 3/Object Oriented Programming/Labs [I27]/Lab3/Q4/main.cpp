#include <iostream>
#include "numberPackage.hpp"

using namespace std;

typedef int (NumberPackage::*FuncPtr)(int);

int main () {
    NumberPackage test;
    int n;

    cout << "Enter the number you want the calculation to be performed on: ";
    cin >> n;
    test.init(n);

    FuncPtr funcs[] = {
        &NumberPackage::factorial,
        &NumberPackage::fibonacii,
        &NumberPackage::sigma,
        &NumberPackage::sigma2,
        &NumberPackage::sigma3
    };

    int choice = 0;
    while ((cout << "1. Factorial" << endl 
                 << "2. Fibonacci" << endl
                 << "3. Summation" << endl
                 << "4. Square Summation" << endl
                 << "5. Cube Summation" << endl
                 << "6. Exit" << endl 
                 << "Please Enter a valid Input: ") && 
                 (cin >> choice) && (choice != 6)) {

        if ((choice >= 1) && (choice <= 5)) {
            FuncPtr selectedFunc = funcs[choice - 1];
            cout << "Result: " << (test.*selectedFunc)(test.getVal()) << endl << endl;
        }
		else
            cout << "Please enter a valid input!" << endl << endl;
        
    }

    cout << "Exiting..." << endl;

    return 0;
}
