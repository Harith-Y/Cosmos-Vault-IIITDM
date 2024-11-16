// Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{
	int a;
	int b,c;
	printf("Please enter the weight of the package in kilograms : ");
	scanf("%d",&a);
	printf("Please enter 1 for Domestic Destination and 0 for International Destination : ");
	scanf("%d",&b);
	
	if (b==1)
		{
			if ((a>0) && (a<=1))
				printf("The Shipping Cost is 5 INR");
			else if ((a>=1) && (a<=5))
				printf("The shipping Cost is 10 INR");
			else if (a==0)
				printf("No Shipping Cost");
			else if (a>5)
				{
					c=((a-5)*2)+ 10;
					printf("The Shipping Cost is %d",c);
				}
			else
				printf("Enter a valid Input");
		}

	else if (b==0)
		{
			if ((a>0) && (a<=1))
				printf("The Shipping Cost is 10 INR");
			else if ((a>=1) && (a<=5))
				printf("The shipping Cost is 20 INR");
			else if (a==0)
				printf("No Shipping Cost");
			else if (a>5)
				{
					b=((a-5)*2)+ 20;
					printf("The Shipping Cost is %d",b);
				}
			else
				printf("Enter a valid Input");
		}
		
	else
		printf("Enter a Valid Input !");


}
