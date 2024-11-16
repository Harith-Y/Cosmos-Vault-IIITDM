#include<stdio.h>
void main()
{
    int num,x=0;
    int i;
    printf("Please enter a number to check whether it is a Prime number or not : ");
    scanf(" %d",&num);
    
    if ((num==0)||(num==1))
        x=1;
    else if (num<0)
        x=2;
        
    for (i=2;i<=num/2;i++)
    {
        if (num%i==0)
        {
            x=3;
            break;
        }

    }
    
    if (x==0)
        printf("%d is a Prime number.",num);
    else if (x==1)
        printf("%d cannot be determined if it is a Prime number or not !",num);
    else if (x==2)
        printf("Please enter a Positive Integer greater than 1 !");
    else
        printf("%d is not a Prime number.",num);
    
}