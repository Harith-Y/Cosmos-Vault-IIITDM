#include<stdio.h>
struct Data
{
    int day,month,year;
} input[2];
void main()
{
    printf("Please enter the Day, Month and year of the first Date : ");
    scanf("%d %d %d", &input[0].day,&input[0].month,&input[0].year);
    printf("Please enter the Day, Month and year of the Second Date : ");
    scanf("%d %d %d", &input[1].day,&input[1].month,&input[1].year);
    
    
    if ((input[0].day<0)||(input[1].day<0)||(input[0].day>31)||(input[1].day>31)||(input[0].month<0)||(input[1].month<0)||(input[0].month>12)||(input[1].month>12))
        printf("Please enter Valid Input !");
    else
    {
        if ((input[0].day==input[1].day)&&(input[0].month==input[1].month)&&(input[0].year==input[1].year))
            printf("Dates are equal");
        else
        printf("Dates are not equal");
    }
}