//Harith Y, B2, CS23I1027
#include<stdio.h>
void main()
{
	int date,month;
	char year;
	printf("Please enter the date in integral form : ");
	scanf("%d",&date);
	printf("Please enter the month in integral form : ");
	scanf("%d",&month);
	printf("Please enter Y if the year is a leap year and N if it is not a leap year : ");
	scanf(" %c",&year);
	
	switch(month)
	{
		case 1:
			printf("The season is Winter");
			break;		
		case 3:
			printf("The season is Spring");
			break;
		case 4:
			printf("The season is Spring");
			break;
		case 5:
			printf("The season is Spring");
			break;
		case 6:
			printf("The season is Summer");
			break;
		case 7:
			printf("The season is Summer");
			break;
		case 8:
			printf("The season is Summer");
			break;
		case 9:
			printf("The season is Fall");
			break;
		case 10:
			printf("The season is Fall");
			break;
		case 11:
			printf("The season is Fall");
			break;
		case 12:
			printf("The season is Winter");
			break;
		case 2:
			switch(year)
			{
				case 'Y':
					printf("This season is Winter (Leap Year)");
					break;
				case 'N':
					printf("This season is Winter");
					break;
				default:
					printf("Please enter a valid input");	
			
			}
			break;
		default:
			printf("Please enter a valid input");	
	
	}
}

