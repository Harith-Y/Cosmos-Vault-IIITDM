#include <stdio.h>  
#include <string.h>  

void main()  
{
    char a[1000];
    int x,i,j;
    
    printf("Please enter a string : ");
    gets(a);

    for (i=0;i<strlen(a);i++)
    {
        x=1;
        for (j=i+1;j<strlen(a);j++)
        {
            if ((a[i]==a[j])&&(a[i]!=' '))
            { 
                x++;
                a[j]='0';
            }
        }

        if ((x>1)&&(a[i]!='0'))
            printf("%c : %d\n",a[i],x);
        
        else if ((x=1)&&(a[i]!='0')&&(a[i]!=' '))
            printf("%c : 1\n",a[i]);
    }

}
