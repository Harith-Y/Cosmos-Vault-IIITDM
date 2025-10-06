#include "Armadams.hpp"

void ArmadamsPackage :: generateAdamsNumbers(int lower, int upper) {
    cout << "Adam numbers between " << lower << " and " << upper << " are: ";
    bool found = false;
    for (int num = lower; num <= upper; num++) {
        if (isAdamNumber(num)) {
            cout << num << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;
}
