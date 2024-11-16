#include<stdio.h>
void main()
{
    int n,on;
    printf("Please enter a number : ");
    scanf(" %d",&n);
    on=n;
    if (n%2!=0)
        {
            printf("%d, ",n);
            while (n>2)
                {
                    n=n-2;
                    printf("%d, ",n);
                    
                }
        }
    
    else    
        {
            n=n-1;
            printf("%d, ",n);
            while (n>2)
                {
                    n=n-2;
                    printf("%d, ",n);
                    
                }
        }
        
    printf(" are the odd numbers till %d. \n",on);
    
}