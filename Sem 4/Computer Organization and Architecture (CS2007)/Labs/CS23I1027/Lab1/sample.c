#include <stdio.h>

void sample_func(int a, int b) {
	int product;
	product = a * b;
	printf("Product: %d\n", product);
}

int main() {

	int a = 5, b = 10, sum = 0;
	sample_func(a, b);
	sum = a + b;
	printf("Sum: %d\n", sum);
	return 0;
}
