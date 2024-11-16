#include<stdio.h>
void main()
{
    int l,x,Case=0;
    char a[1000];
    printf("Please enter a string : ");
    scanf(" %s",a);
    
    for (l=0;a[l] != '\0';l++);
    
    x=0;
    l=l-1;
    while (x<l)
    {
        if (a[x++] != a[l--])
            Case=1;
    }
    
    if (Case == 1)
        printf("%s is not a palindrome.\n",a);
    else
        printf("%s is a palindrome.\n",a);
    
}