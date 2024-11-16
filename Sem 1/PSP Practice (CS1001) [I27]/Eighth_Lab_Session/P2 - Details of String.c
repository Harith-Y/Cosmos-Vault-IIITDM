#include<stdio.h>
#include<string.h>
void main()
{
    int v=0,c=0,d=0,ws=0,l;
    char a[1000];
    printf("Enter a line of string : ");
    gets(a);
    l=strlen(a);
    
    for (int i=0;a[i] != '\0';i++)
    {
        if ((a[i]=='a')||(a[i]=='A')||(a[i]=='e')||(a[i]=='E')||(a[i]=='i')||(a[i]=='I')||(a[i]=='o')||(a[i]=='O')||(a[i]=='u')||(a[i]=='U'))
            ++v;
        else if ((a[i]>='A')&&(a[i]<='z')&&(a[i]!='a')&&(a[i]!='A')&&(a[i]!='e')&&(a[i]!='E')&&(a[i]!='i')&&(a[i]!='I')&&(a[i]!='o')&&(a[i]!='O')&&(a[i]!='u')&&(a[i]!='U'))
            ++c;
        else if ((a[i]=='0')||(a[i]=='1')||(a[i]=='2')||(a[i]=='3')||(a[i]=='4')||(a[i]=='5')||(a[i]=='6')||(a[i]=='7')||(a[i]=='8')||(a[i]=='9'))
            ++d;
        else if (a[i]==' ')
            ++ws;
    }
    
    printf("Vowels : %d\nConsonants : %d\nDigits : %d\nWhite Spaces : %d\n",v,c,d,ws);
    
}