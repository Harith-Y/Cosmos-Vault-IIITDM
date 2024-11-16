#include<stdio.h>
void main()
{
    int x=0;
    char a[1000],n;
    printf("Enter the string : ");
    gets(a);
    printf("Enter a charecter to find its frequency : ");
    scanf(" %c",&n);
    
    for (int i=0;a[i] != '\0';i++)
    {
        if (a[i]==n)
            ++x;
    }
    
    printf("The frequency of %c is %d. \n",n,x);
    
}