#include<stdio.h>
void main()
{
    
    int b,e,ob,oe;
    int n=1;
    printf("Please enter the Base : ");
    scanf(" %d", &b);
    ob=b;
    if (b>=0)
    {
        printf("Please enter the Exponent : ");
        scanf(" %d", &e);
        oe=e;
        if (e>0)
        {
            while (e>0)
            {
                n=n*b;
                --e;
            }
            printf("%d ^ %d is %d",b,oe,n);
        }
        else if (e==0)
        {
            if (b>0)
                printf("%d ^ 0 = 1",b);
            else
                printf("The result is Undefined. \n");
            
        }
        else
        {
            e=-e;
            while (e>0)
            {
                n=n*b;
                --e;
            }
            printf("%d ^ %d is 1/%d",b,oe,n);
        }
    }
    
    else
    {
        printf("Please enter the Exponent : ");
        scanf(" %d", &e);
        oe=e;
        if (e>0)
        {
            if (e%2==0)
            {
                b=-b;
                while (e>0)
                {
                    
                    n=n*b;
                    --e;
                    
                }
                printf("(-%d) ^ %d is %d",ob,oe,n);
            }
            else 
            {
                b=-b;
                while (e>0)
                {
                    
                    n=n*b;
                    --e;
                    
                }
                printf("%d ^ %d is -%d",b,oe,n);
            }
        }
        else if (e==0)
            printf("%d ^ 0 = 1",b);
        else
        {   
            e=-e;
            if (e%2==0)
            {
                b=-b;
                while (e>0)
                {
                    
                    n=n*b;
                    --e;
                    
                }
                printf("(%d) ^ (%d) is 1/%d",ob,oe,n);
            }
            else 
            {
                b=-b;
                while (e>0)
                {
                    
                    n=n*b;
                    --e;
                    
                }
                printf("(-%d) ^ (%d) is -1/%d",b,oe,n);
            }
            
        }
    
    }
        
}