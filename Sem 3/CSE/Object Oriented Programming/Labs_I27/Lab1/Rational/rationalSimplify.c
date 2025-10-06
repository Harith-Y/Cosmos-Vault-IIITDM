#include <stdio.h>
#include "rational.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

struct rational rationalSimplify(struct rational result) {

	struct rational Simplified;
	if (result.denominator == 0) {
		printf("Error. Denominator cannot be zero.\n");
		result.numerator = 0;
		result.denominator = 1;
		return result;
    }

    int commonDivisor = gcd(result.numerator, result.denominator);
    result.numerator /= commonDivisor;
    result.denominator /= commonDivisor;

    if (result.denominator < 0) {
		result.denominator = -result.denominator;
		result.numerator = -result.numerator;
    }
    
    Simplified = result;

    return Simplified;
}
   
