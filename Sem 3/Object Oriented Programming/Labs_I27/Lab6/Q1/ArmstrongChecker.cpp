#include "Armadams.hpp"
#include <cmath>

bool ArmadamsPackage :: isArmstrongNumber(int testNum) {
    int num = testNum;
    int sum = 0;
    int n = 0;

    while (num != 0) {
        num /= 10;
        n++;
    }

    num = testNum;

    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, n);
        num /= 10;
    }

    return (sum == testNum);
}
