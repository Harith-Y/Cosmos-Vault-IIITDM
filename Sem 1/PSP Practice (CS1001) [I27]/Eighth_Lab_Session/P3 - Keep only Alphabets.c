#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,l;
    char a[1000];
    printf("Enter a string : ");
    gets(a);
    //l=strlen(a);
    
    for (i=0;i<strlen(a);i++)
    {
        if ((a[i]>='A')&&(a[i]<='z'))
            continue;
        else
        {
            for (j=i;j<strlen(a);j++)
            {
                a[j]=a[j+1];
            }
        i--;
        }
    }
    
    puts(a);

}