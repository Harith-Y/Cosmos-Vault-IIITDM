//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	int a,b;
	printf("Enter the first number\n");
	scanf("%d",&a);
	printf("Enter the second number\n");
	scanf("%d",&b);
	a=a*b;
	b=a/b;
	a=a/b;
	printf("The Swapped First number is %d \n",a);	
	printf("The Swapped second number is %d \n",b);
}