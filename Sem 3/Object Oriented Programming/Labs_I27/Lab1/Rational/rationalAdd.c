#include "rational.h"

struct rational rationalAdd(struct rational a, struct rational b) {

	struct rational result;

    if ((a.denominator == 0) || (b.denominator == 0)) {
        printf("Error. Denominator cannot be zero.\n");
        result.numerator = 0;
        result.denominator = 1;
        return result;
    }

    result.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
    result.denominator = a.denominator * b.denominator;

    struct rational Result = rationalSimplify(result);
	return Result;
}

