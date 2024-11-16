//Harith Y (B2), CS23I1027
#include<stdio.h>
#include<math.h>
void main()
{
	int C,R,Q,c,d;
	float A,S,M,D,a,b,P;
	printf("If you want to add 2 numbers, Please press 1\n");
	printf("If you want to subtract 2 numbers, Please press 2\n");
	printf("If you want to multiply 2 numbers, Please press 3\n");
	printf("If you want to divide 2 numbers, Please press 4\n");
	printf("If you want to find the remainder if you divide 2 numbers, Please press 5\n");
	printf("If you want to raise a number to any power, Please press 6\n");
	scanf("%d",&C);
	
	if (C==1)
		{
		printf("Please enter the first number : ");
		scanf("%f",&a);
		printf("Please enter the number you want the first number to be added with : ");
		scanf("%f",&b);
		A=a+b;
		printf("The sum is %f \n",A);
		}
	
	else if (C==2)
		{
		printf("Please enter the first number : ");
		scanf("%f",&a);
		printf("Please enter the number you want the first number to be subtracted from : ");
		scanf("%f",&b);
		S=a-b;
		printf("The difference is %f \n",S);
		}
	
	else if (C==3)
		{
		printf("Please enter the first number : ");
		scanf("%f",&a);
		printf("Please enter the number you want the first number to be multiplied with : ");
		scanf("%f",&b);
		M=a*b;
		printf("The product is %f \n",M);
		}
	
	else if (C==4)
		{
		printf("Please enter the first number : ");
		scanf("%f",&a);
		printf("Please enter the number you want the first number to be divided by : ");
		scanf("%f",&b);

		if (b==0)

			{
				printf("Division by 0 is not defined.");
			}

		else if (a==0 && b==0)

			{
				printf("Result is Undefined");
			}
	

		else
			{
				D=a/b;
				printf("The result is %f \n",D);
			}

		}
	
	else if (C==5)
		{
		printf("Please enter the first number : ");
		scanf("%d",&c);
		printf("Please enter the number you want the first number to be divided by : ");
		scanf("%d",&d);
		
		if (b==0)

			{
				printf("Division by 0 is not defined.");
			}


		else if (a==0 && b==0)

			{
				printf("Result is Undefined");
			}

		else
			{
			Q=c/d;
			R=c%d;
			printf("The quotient is %d ",Q);
			printf("and the remainder is %d \n",R);
			}
		
		
		}
	
	else if (C==6)
		{
		printf("Please enter a number : ");
		scanf("%f",&a);
		printf("Please enter the power you want the entered number to be raised by : ");
		scanf("%f",&b);
		P=pow(a,b);
		printf("The result is %f ",P);
		}

	else
		{ 
		printf("You have entered an Invalid Input. \nThere are only Limited Functions as I am not that Skilled as a programmer yet.\n");
		}
}
 //     cd /mnt/c/Users/yhari/Documents/C/Second_Lab_Session
 //     gcc BasicCalc.c -o BasicCalc
 //     ./BasicCalc