#include<stdio.h>
void samp_func(int a, int b)
{
	int product;
	product=a*b;
	printf("Product: %d\n", product);
}
int main()
{
	int x = 5;
	int y = 10;
	int result = 0;
	samp_func(x,y);
	result = x + y;
	printf("Result: %d\n", result);
	return 0;
}
