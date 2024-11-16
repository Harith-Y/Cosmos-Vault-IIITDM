#include<stdio.h>
int fibonaccifn(int,int,int);
int main()
{
    int a,b,c;
    
    return fibonaccifn(a,b,c);
}
int fibonaccifn(int x, int y, int n)
{
    int a,b,c,s,i;
    printf("Please enter the two starting numbers to form a Fibonacci Sequence : ");
    scanf("%d %d",&a,&b);
    printf("Please enter number of terms in the Fibonacci Sequence : ");
    scanf("%d",&c);
    i=2;
    if (c==1)
        printf("%d",a);
    else if (c==2)
        printf("%d, %d",a,b);
    else if (c>2)
        printf("%d, %d, ",a,b);
    while (i<=(c-1))
    {
        s=a+b;
        //printf("%d",s);
        i++;
        a=b;
        b=s;
        if (i!=c)
            printf("%d, ",s);
        if (i==(c-1))
            printf("%d",s+a);
    }
    
}