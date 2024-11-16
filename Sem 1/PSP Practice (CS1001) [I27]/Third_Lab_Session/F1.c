// Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{
	char a;
	float b;
	float c;
	printf("Are you a member or not, Press Y for Yes and N for No : ");
	scanf("%c",&a);
	
	
	if (a == 'Y')
		{	
			printf("Please enter the Purchase amount in Dollars : ");
			scanf("%f",&b);
			if (b>100)
				{
					printf("Congratulations ! You have recieved a 10 Percent Discount \n");
					c = (9/10)*(b);
					printf("The amount you should pay is %f$",c);
				}
			else if (b<=100)
				{
					printf("Sorry, You are not eligible for any discount \n");
					printf("The amount you should pay is %f$",b);
				}
			else
				printf("Please enter a Valid Input");
				
		}
	else if (a == 'N')
		{	
			printf("Please enter the Purchase amount in Dollars : ");
			scanf("%f",&b);
			if (b>100)
				{
					printf("Congratulations ! You have recieved a 5 Percent Discount \n");
					c = (95/100)*(b);
					printf("The amount you should pay is %f$",c);
				}
			else if (b<=100)
				{
					printf("Sorry, You are not eligible for any discount \n");
					printf("The amount you should pay is %f$",b);
				}
			else
				printf("Please enter a Valid Input");
		}
	else
		printf("You have entered an invalid input. Please Enter Y for Yes and N for No");
		
	
}
