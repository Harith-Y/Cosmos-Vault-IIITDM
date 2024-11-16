// Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{
	int day,month;
	printf("Enter the Integral value of Day of the week : ");
	scanf(" %d",&day);
	if ((day==1) || (day==2) || (day==3) || (day==4) || (day==5) || (day==6) || (day==7))
		{
		printf("Enter the Integral value of Month : ");
		scanf(" %d",&month);
		if ((month==1) || (month==2) || (month==3) || (month==4) || (month==5) || (month==6) || (month==7) || (month==8) || (month==9) || (month==10) || (month==11) || (month==12))	
			{
			if (day==1)
				printf("The entered day of the week is Sunday");
			else if (day==2)
				printf("The entered day of the week is Monday");
			else if (day==3)
				printf("The entered day of the week is Tuesday");
			else if (day==4)
				printf("The entered day of the week is Wednesday");
			else if (day==5)
				printf("The entered day of the week is Thursday");
			else if (day==6)
				printf("The entered day of the week is Friday");
			else
				printf("The entered day of the week is Saturday");
			printf(" and ");
			
			if (month==1)
				printf("the entered month is January. \n");
			else if (month==2)
				printf("the entered month is February. \n");
			else if (month==3)
				printf("the entered month is March. \n");
			else if (month==4)
				printf("the entered month is April. ]n");
			else if (month==5)
				printf("the entered month is May. \n");
			else if (month==6)
				printf("the entered month is June. \n");
			else if (month==7)
				printf("the entered month is July. \n");
			else if (month==8)
				printf(" the entered month is August. \n");
			else if (month==9)
				printf("the entered month is September. \n");
			else if (month==10)
				printf("the entered month is October. \n");
			else if (month==11)
				printf("the entered month is November. \n");
			else
				printf("the entered month is December. \n");
			}
		else
			printf("Please enter a valid Input !");
		}

	else
		printf("Please enter a valid Input !");		







}
