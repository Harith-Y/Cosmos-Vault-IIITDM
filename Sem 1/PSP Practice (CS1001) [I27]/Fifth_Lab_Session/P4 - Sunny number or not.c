#include<stdio.h>
void main()
{
    
    int num,i,x,Case;
    printf("Please enter a number to check whether it is Sunny number or not : ");
    scanf(" %d",&num);
    num=num+1;
   
    if (num>1)
    {
        for (i=1;i<num;i++)
        {
            x=i*i;
            if (x==num)
            {
                Case=1;
                break;
            }
            
        }
        
        if (Case==1)
            printf("Success. %d is a Sunny number !",num-1);
        else
            printf("Oh no ! %d is not a Sunny number.",num-1);
    }
    
    else if (num==1)
        printf("Success. 0 is a Sunny number !");
    else if (num==0)
        printf("Success. -1 is a Sunny number !");
    else
        printf("Please enter a valid Input. A Square of any number has to be non-negative !");
    
}