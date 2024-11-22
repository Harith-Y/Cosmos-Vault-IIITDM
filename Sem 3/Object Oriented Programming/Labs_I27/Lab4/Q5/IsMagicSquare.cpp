#include "SquarePackage.hpp"

bool SquarePackage :: isMagicSquare() const {
    int magicSum = rowSum(0);

    for (int i = 1; i < size; i++)
        if (rowSum(i) != magicSum)
            return false;

    for (int j = 0; j < size; j++)
        if (colSum(j) != magicSum)
            return false;

    if ((diagSum(true) != magicSum) || (diagSum(false) != magicSum))
        return false;

    return true;
}
