#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *copyfrom, *copyto;
    char c;
    copyfrom=fopen("file1.txt","r");
    copyto=fopen("file2.txt","w");
    
    if ((copyfrom==NULL)||(copyto==NULL))
    {
        printf("Error\n");
        exit(1);
    }
    
    else
    {
        while ((c=fgetc(copyfrom))!=EOF)
        {
            fputc(c,copyto);
        }
        fcloseall();
    }
    
}
