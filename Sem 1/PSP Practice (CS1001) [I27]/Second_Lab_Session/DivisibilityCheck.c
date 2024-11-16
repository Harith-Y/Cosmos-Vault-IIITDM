//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	int a,b,c,d;
	printf("Please enter the number whose divisibility needs to be checked\n");
	scanf("%d",&a);
	printf("Please enter the number you want the first number to be divided by\n");
	scanf("%d",&b);
	c=a%b;
	d=a/b;
	
	if (a%b==0)
		{
		printf("Given Number is divisible by %d ",b);
		printf("and the quotient is %d \n",d);
		}
	else
		{ 
		printf("Given Number is not divisible by %d ",b);
		printf(", the quotient is %d \n",d);
		printf("and the Remainder is %d \n",c);
		}
}
