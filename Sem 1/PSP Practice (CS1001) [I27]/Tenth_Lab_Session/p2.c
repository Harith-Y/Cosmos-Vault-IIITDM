//Write a program in C to print all permutations of a given string using pointers.
#include<stdio.h>
#include<string.h>

void permute_fn(char*,int,int);

void main()

{
	char arr[4];
	int length,i,j;
	char *p1,*p2,*p3,*p4;
	printf("Please enter a string : ");
	gets(arr);
	
	
	if (strlen(arr)==0)
		printf("Please enter a string !\n");
		
	else if (strlen(arr)==1)
		printf("%c\n",arr[0]);
	
	else if (strlen(arr)==2)
		printf("%c%c %c%c\n",arr[0],arr[1],arr[1],arr[0]);
	
	else if (strlen(arr)==3)
		permute_fn(arr,0,2);
	
	else if (strlen(arr)==4)
		permute_fn(arr,0,3);
	
	else
		printf("%ld",strlen(arr));
		printf("Please enter a string of length less than or equal to 4 !\n");
		

}

void permute_fn(char* entry, int left, int right) 
{ 
    int i;
    if (left==right) 
        printf("%s ",entry); 
    else 
    { 
        for (i=left;i<=right;i++)
        {
            char x;
	    x=(*(entry+left));
	    (*(entry+left))=(*(entry+i));
	    (*(entry+i))=x;
            
            permute_fn(entry,left+1,right);
            
	    x=(*(entry+left));
	    (*(entry+left))=(*(entry+i));
	    (*(entry+i))=x;
        } 
    } 
}






