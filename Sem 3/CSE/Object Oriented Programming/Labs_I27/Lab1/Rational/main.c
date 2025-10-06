#include <stdio.h>
#include "rational.h"

int main() {

	struct rational a, b;
	
	printf("Enter numerator and denominator for the first rational number: ");
    scanf("%d %d", &a.numerator, &a.denominator);
    if (a.denominator == 0) {
        printf("Error. Denominator cannot be zero.\n");
        return 1;
    }

    printf("Enter numerator and denominator for the second rational number: ");
    scanf("%d %d", &b.numerator, &b.denominator);
    if (b.denominator == 0) {
        printf("Error. Denominator cannot be zero.\n");
        return 1;
    }

	int choice = 0;
	
	while (printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Quit\nPlease Enter an Integer: ") && choice != 5 && scanf(" %d", &choice)) {

		if (choice == 1) {
			struct rational c = rationalAdd(a, b);
			printf("Result of addition: %d/%d\n", c.numerator, c.denominator);
		}
		
		else if (choice == 2) {
			struct rational c = rationalSubtract(a, b);
			printf("Result of subtraction: %d/%d\n", c.numerator, c.denominator);
		}
		
		else if (choice == 3) {
			struct rational c = rationalMultiply(a, b);
			printf("Result of multiplication: %d/%d\n", c.numerator, c.denominator);
		}
		
		else if (choice == 4) {
			struct rational c = rationalDivide(a, b);
			printf("Result of division: %d/%d\n", c.numerator, c.denominator);
		}
		
		else
			printf("Please enter a valid choice!\n");
    }

	return 0;
}

