#include<stdio.h>
void main()
{
    int num,i,x;
    printf("Please enter a number : ");
    scanf(" %d",&num);
    
    if (num<=0)
        printf("You have entered an invalid input ! Please enter a Natural number.");
    else 
    {
        x=0;
        for (i=1;i<=num;i++)
        {
            x=x+i;
        }
        printf("The sum of all the natural numbers till %d is %d",num,x);
        
    }
    
}