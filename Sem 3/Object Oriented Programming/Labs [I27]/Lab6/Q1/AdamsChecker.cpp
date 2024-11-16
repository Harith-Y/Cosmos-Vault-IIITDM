#include "Armadams.hpp"

int ArmadamsPackage :: reverseNumber(int num) {
    int reversedNum = 0;
    while (num > 0) {
        reversedNum = (reversedNum * 10) + (num % 10);
        num /= 10;
    }

    return reversedNum;
}

bool ArmadamsPackage :: isAdamNumber(int num) {
    int square = num * num;
    int reversedNum = reverseNumber(num);
    int reversedSquare = reverseNumber(reversedNum * reversedNum);

    return (square == reversedSquare);
}   