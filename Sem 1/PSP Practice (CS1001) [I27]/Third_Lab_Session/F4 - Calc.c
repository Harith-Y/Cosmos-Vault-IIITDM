//Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{
	float a,b,c;
	int d,e,f,g;
	int mainchoice;
	char choice;
	printf("Enter 1 if you want to perform Arithmetic operations \nEnter 2 if you want to perform Bitwise operations \n");
	scanf("%d",&mainchoice);
	switch(mainchoice)
	{
		case 1:
			printf("Enter the operator : ");
			scanf(" %c",&choice);
			switch(choice)
			{
				case '+':
					printf("Please enter the first value : ");
					scanf("%f",&a);
					printf("Please enter the second value : ");
					scanf("%f",&b);
					c=a+b;
					printf("Sum of %f and %f is %f.",a,b,c);
					break;
				case '-':
					printf("Please enter the first value : ");
					scanf("%f",&a);
					printf("Please enter the second value : ");
					scanf("%f",&b);
					c=a-b;
					printf("Subracting %0.1f from %0.1f gives %0.1f.",b,a,c);
					break;
				case '*':
					printf("Please enter the first value : ");
					scanf("%f",&a);
					printf("Please enter the second value : ");
					scanf("%f",&b);
					c=a*b;
					printf("Product of %f and %f is %f.",a,b,c);
					break;
				case '/':
					printf("Please enter the first value : ");
					scanf("%f",&a);
					printf("Please enter the second value : ");
					scanf("%f",&b);
					c=a/b;
					printf("Dividing %f by %f gives %f.",a,b,c);
					break;
				case '%':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					printf("Please enter the second number : ");
					scanf("%d",&e);
					g=d%e;
					printf("Remainder when %d is divided by %d is %d.",d,e,g);
					break;
				default:
					printf("Enter a valid Input");
			}
			break;
		case 2:
			printf("Enter the operator : ");
			scanf(" %c",&choice);
			switch(choice)
			{
				case '&':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					printf("Please enter the second number : ");
					scanf("%d",&e);
					f=d&e;
					printf("Bitwise AND of %d and %d is %d.",d,e,f);
					break;
				case '|':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					printf("Please enter the second number : ");
					scanf("%d",&e);
					f=d|e;
					printf("Subracting %d from %d gives %d.",d,e,f);
					break;
				case '~':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					f=~d;
					printf("Bitwise NOT of %d is %d.",d,f);
					break;
				case '^':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					printf("Please enter the second number : ");
					scanf("%d",&e);
					f=d^e;
					printf("Exclusive OR of %d and %d is %d.",d,e,f);
					break;
				case '<':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					printf("Please enter the second number : ");
					scanf("%d",&e);
					f=d<<e;
					printf("%d left shift %d is %d.",d,e,f);
					break;
				case '>':
					printf("Please enter the first number : ");
					scanf("%d",&d);
					printf("Please enter the second number : ");
					scanf("%d",&e);
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

