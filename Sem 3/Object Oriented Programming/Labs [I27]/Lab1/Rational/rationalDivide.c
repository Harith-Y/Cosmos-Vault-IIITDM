#include <stdio.h>
#include "rational.h"

struct rational rationalDivide(struct rational a, struct rational b){

	struct rational result;
	
	if ((a.denominator == 0) || (b.denominator == 0)) {
        printf("Error. Denominator cannot be zero.\n");
        result.numerator = 0;
        result.denominator = 1;
        return result;
    }

    if (b.numerator == 0) {
        printf("Error. Division by zero.\n");
        result.numerator = 0;
        result.denominator = 1;
        return result;
    }

    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;

    struct rational Result = rationalSimplify(result);
	return Result;
}

