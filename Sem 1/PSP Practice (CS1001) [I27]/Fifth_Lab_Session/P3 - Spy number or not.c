#include<stdio.h>
void main()
{
    int sum=0,prod=1,num, onum,i,x;
    printf("Please enter a number to check whether it is a Spy number or not : ");
    scanf(" %d",&num);
    onum=num;
    i=num;
    
    if (num>=10)
    {
        for (num=num;num>0;num/=10)
        {
            x=num%10;
            sum=sum+x;
                
        }
        
        for (onum=onum;onum>0;onum/=10)
        {
            x=onum%10;
            prod=prod*x;
                
        }
        
        if (sum==prod)
            printf("Success. %d is a Spy number !",i);
        else
            printf("Alas ! %d is not a Spy number",i);
    
    }
    
    else if ((num>=0) && (num<10))
        printf("Cannot be determined if %d is a Spy number or not. \nPlease enter a Positive Integer greater than or equal to 10.",num);
    else
        printf("Cannot be determined. Please enter a Positive Integer greater than or equal to 10.");
    
    
    
    
    
    
    
}