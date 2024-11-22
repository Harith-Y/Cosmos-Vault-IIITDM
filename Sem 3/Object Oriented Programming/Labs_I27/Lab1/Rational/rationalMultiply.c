#include <stdio.h>
#include "rational.h"

struct rational rationalMultiply(struct rational a, struct rational b){

	struct rational result;

    if ((a.denominator == 0) || (b.denominator == 0)) {
        printf("Error. Denominator cannot be zero.\n");
        result.numerator = 0;
        result.denominator = 1;
        return result;
    }

    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;

    struct rational Result = rationalSimplify(result);
	return Result;
}

