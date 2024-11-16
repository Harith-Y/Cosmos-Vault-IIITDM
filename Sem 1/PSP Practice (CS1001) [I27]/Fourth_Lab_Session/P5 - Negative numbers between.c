#include<stdio.h>
void main()
{
    
    int x,y,c,d;
    printf("Please enter the First number : ");
    scanf("%d",&x);
    printf("Please enter the Second number : ");
    scanf("%d",&y);
    
    if ((x<0) && (y<0))
    {
        if (x<y)
            {
                x=-x;
                y=-y;
                while (y<x-1)
                {
                    y=y+1;
                    printf("-%d, ",y);
                    
                }
                
            }
        else if (x>y)
            {
                x=-x;
                y=-y;
                while (x<y-1)
                {
                    x=x+1;
                    printf("-%d, ",x);
                    
                }
                
            }
    
        else
            printf("No negative numbers between the given two numbers.");
    
    }
    
    else if ((x>0) && (y<0))
    {
        while (y<-1)
        {
            y=y+1;
            printf("%d, ",y);
                    
        }
                
    }
                
    else if ((x<0) && (y>0))
    {
        while (x<-1 )
        {
            x=x+1;
            printf("%d, ",x);
                    
        }
                
    }
    
    else
        printf("No negative numbers between the given two numbers.");
}