#include<stdio.h>
int Primefn(int);
void main()
{
    int num,i,j,k,x;
    printf("Please enter a number : ");
    scanf(" %d",&num);
    
    if (num<=0)
        printf("Please enter a Positive Integer !");
    else if ((num>0)&&(num<4))
        printf("%d cannot be expressed as the sum of two prime numbers !",num);
        
    else
    {   
        x=0;
        for (i=2;i<=num/2;i++)
        {
            if (Primefn(i)==1)
            {
                if (Primefn(num-i)==1)
                {
                    printf("%d = %d + %d\n",num,i,num-i);
                    x=1;
                }
            }
            
        }
    }
    
    if (x==0)
        printf("%d cannot be expressed as the sum of two prime numbers !",num);
}

int Primefn(int num)
{
    int i,y=1;
    for (i=2;i<=num/2;i++)
    {
        if (num%i==0)
        {
            y=0;
            break;
        }
    }
    return y;
    
}