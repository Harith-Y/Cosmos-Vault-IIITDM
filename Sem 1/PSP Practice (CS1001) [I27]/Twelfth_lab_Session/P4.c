#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    char Str1[1000],Str2[1000];
    printf("Enter first string : ");
    gets(Str1);
    int len1=strlen(Str1);
    printf("Enter second string : ");
    gets(Str2);
    
    strcat(Str1,Str2);
    
    char *Str = (char *)malloc(len1*sizeof(char));
    
    if (Str==NULL)
    {
        printf("Memory not allocated !");
        exit(1);
    }
    else
    {
        printf("The concatenated string is : ");
        for (int i=0;i<strlen(Str1);i++)
        {
            *(Str+i)=Str1[i];
            printf("%c",*(Str+i));
        }
        
    free(Str);
    Str=NULL;
        
    }
}