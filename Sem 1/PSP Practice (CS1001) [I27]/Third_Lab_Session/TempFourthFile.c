//Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{
	float a,b,c;
	int d,e,f,g;
	int mainchoice, choice;
	printf("Enter 1 if you want to perform Arithmetic operations \nEnter 2 if you want to perform Bitwise operations \n");
	scanf("%d",&mainchoice);
	switch(mainchoice)
	{
		case 1:
			printf("Please enter the first value : ");
			scanf("%f",&a);
			printf("Please enter the second value : ");
			scanf("%f",&b);
			printf("Enter 1 for Addition \nEnter 2 for Subtraction \nEnter 3 for Multiplication \nEnter 4 for Division \nEnter 5 for Remainder \n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					c=a+b;
					printf("Sum of %f and %f is %f.",a,b,c);
					break;
				case 2:
					c=a-b;
					printf("Subracting %f from %f gives %f.",b,a,c);
					break;
				case 3:
					c=a*b;
					printf("Product of %f and %f is %f.",a,b,c);
					break;
				case 4:
					c=a/b;
					printf("Dividing %f by %f gives %f.",a,b,c);
					break;
				case 5:
					//g=a%b;
					//printf("Remainder when %f is divided by %f is %f.",a,b,g);
					//break;
				default:
					printf("Enter a valid Input");
			}
			break;
		case 2:
			printf("Please enter the first number : ");
			scanf("%d",&d);
			printf("Please enter the second number : ");
			scanf("%d",&e);
			printf("Enter 1 for Bitwise AND \nEnter 2 for Bitwise OR \nEnter 3 for Bitwise NOT \nEnter 4 for Bitwise EXCLUSIVE OR \nEnter 5 for Left Shift \nEnter 6 for Right Shift\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					f=d&e;
					printf("Bitwise AND of %d and %d is %d.",d,e,f);
					break;
				case 2:
					f=d|e;
					printf("Subracting %d from %d gives %d.",d,e,f);
					break;
				//case 3:
				//	f=d~e;
				//	printf("Product of %d and %d is %d.",d,e,f);
				//	break;
				case 4:
					f=d^e;
					printf("Exclusive OR of %d and %d is %d.",d,e,f);
					break;
				case 5:
					f=d<<e;
					printf("%d left shift %d is %d.",d,e,f);
					break;
				case 6:
					f=d>>e;
					printf("%d right shift %d is %d.",d,e,f);
					break;
				default:
					printf("Enter a valid Input");
			}
			break;
		default:
			printf("Enter a valid Input");


	}	
	
}

