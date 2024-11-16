//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Please enter the Length of Base of the Triangle\n");
	scanf("%d",&a);
	printf("Please enter the Length of the Altitude of the Triangle\n");
	scanf("%d",&b);
	c=(0.5)*a*b;
	printf("The Area of the Triangle with given dimensions is %d \n",c);
}
