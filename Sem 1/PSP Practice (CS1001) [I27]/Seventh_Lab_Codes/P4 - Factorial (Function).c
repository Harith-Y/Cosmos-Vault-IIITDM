#include<stdio.h>
int factorialfn(int n);
void main()
{
    int f,x;
    printf("Please enter a number : ");
    scanf(" %d",&x);
    if (x<0)
        printf("Factorial of Negative numbers is undefined !");
    //else if ((x==0)||(x==1))
        //printf("Factorial of %d is 1",x);
    else
    {
        f=factorialfn(x);
        printf("The factorial of %d is %d",x,f);
    }

}

int factorialfn(int n)
{
    if (n==0)
        return 1;
    else
        return (n*factorialfn(n-1));
}