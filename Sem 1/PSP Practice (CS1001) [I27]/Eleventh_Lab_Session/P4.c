#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *txt;
    char input_string[1000];
    txt=fopen("file3.txt","w");
    
    if (txt==NULL)
    {
        printf("Error !\n");
        exit(1);
    }
    
    else
    {
    	printf("Enter a string : ");
       	gets(input_string);
        fprintf(txt,"%s",input_string);
        fclose(txt);
    }
}
