#include <iostream>
#include "Armadams.hpp"

using namespace std;

int main() {
    int choice = 0;

    while ((cout << "\nChoose an option:" << endl 
             << "1. Check if a number is Adams Number." << endl 
             << "2. Check if a number is Armstrong Number." << endl
             << "3. Generate a list of Armstrong Numbers." << endl
             << "4. Generate a list of Adams Numbers" << endl
             << "5. Exit" << endl
             << "Enter a valid choice: ") && (cin >> choice)) {

        if (choice == 1) {
            int n;
            cout << "Enter a number: ";
            cin >> n;

            ArmadamsPackage armadams(n);

            if (armadams.isAdamNumber(armadams.getNum()))
                cout << armadams.getNum() << " is an Adam number." << endl;
            else
                cout << armadams.getNum() << " is not an Adam number." << endl;
        }

        else if (choice == 2) {
            int n;
            cout << "Enter a number: ";
            cin >> n;

            ArmadamsPackage armadams(n);

            if (armadams.isArmstrongNumber(armadams.getNum()))
                cout << armadams.getNum() << " is an Armstrong number." << endl;
            else
                cout << armadams.getNum() << " is not an Armstrong number." << endl;
        }

        else if (choice == 3) {
            int n = 0;
            ArmadamsPackage armadams(n);

            int low = 0, high = 0;
            cout << "Enter Lower Bound: ";
            cin >> low;
            cout << "Enter Upper Bound: ";
            cin >> high;
            armadams.generateArmstrongNumbers(low, high);
        }

        else if (choice == 4) {
            int n = 0;
            ArmadamsPackage armadams(n);

            int low = 0, high = 0;
            cout << "Enter Lower Bound: ";
            cin >> low;
            cout << "Enter Upper Bound: ";
            cin >> high;
            armadams.generateAdamsNumbers(low, high);
        }

        else if (choice == 5) {
            cout << "Exiting...\n" << endl;
            break;
        }

        else
            cout << "Invalid choice!" << endl;
    }

    return 0;
}