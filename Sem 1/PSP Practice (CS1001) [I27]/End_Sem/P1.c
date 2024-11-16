#include<stdio.h>

int fact(int num)
{
    if ((num==0)||(num==1))
        return 1;
    else    
        return num*fact(num-1);
}

int power(int base, int exponent)
{
    if (exponent==1)
        return 1;
    else
        return base*power(base,exponent-1);
}

int powerfn(int base, int exponent)
{
    int i,result=1;
    for (i=0;i<exponent;i++)
        result=result*base;
    return result;
}

void main()
{
    int n,m,p;
    scanf(" %d",&n);
    scanf(" %d",&m);
    scanf(" %d",&p);

    int k1 = fact(n) - powerfn(m,p); 
    int k2 = fact(n) - power(m,p+1);
    printf("\n%d",k1); //Or k2
}
