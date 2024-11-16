#include "Armadams.hpp"

using namespace std;

void ArmadamsPackage :: generateArmstrongNumbers(int lower, int upper) {
    cout << "Armstrong numbers between " << lower << " and " << upper << " are: ";
    bool found = false;
    for (int num = lower; num <= upper; num++) {
        if (isArmstrongNumber(num)) {
            cout << num << " ";
            found = true;
        }
    }
    if (!found)
        cout << "None";

    cout << endl;
}