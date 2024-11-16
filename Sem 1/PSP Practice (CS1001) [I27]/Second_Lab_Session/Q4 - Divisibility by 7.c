//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	int a;
	printf("Please enter the number which needs to be checked whether it is divisible by 7 or not \n");
	scanf("%d",&a);
	
	if (a%7==0)
		{
		printf("Given Number is divisible by 7, It is a Buzz Number \n");
		}
	else if (a%7==1)
		{ 
		printf("Given Number is not divisible by 7 and the Remainder is 1 \n");
		}
	else if (a%7==2)
		{ 
		printf("Given Number is not divisible by 7 and the Remainder is 2 \n");
		}
	else if (a%7==3)
		{ 
		printf("Given Number is not divisible by 7 and the Remainder is 3 \n");
		}
	else if (a%7==4)
		{ 
		printf("Given Number is not divisible by 7 and the Remainder is 4 \n");
		}
	else if (a%7==5)
		{ 
		printf("Given Number is not divisible by 7 and the Remainder is 5 \n");
		}
	else
		{ 
		printf("Given Number is not divisible by 7 and the Remainder is 6 \n");
		}
}
