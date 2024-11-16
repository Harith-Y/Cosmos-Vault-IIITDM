#include<stdio.h>
void main()
{
    int a,b;
    int n=1;
    int x=1;
    printf("Please Enter the number you want to find the factorial of : ");
    scanf("%d",&a);
    b=a;
    
    if (a<0)
        printf("Please enter a non-negative Integer !");
    else if (a==0)
        printf("0! = 1");
    else if (a>0)
        {
            while (n<=a)
            {
                x*=n;
                n++;
            }
            
            printf("%d! = %d",a,x);
            
        }
    else
        printf("Please enter a Valid Integer !");
    

}