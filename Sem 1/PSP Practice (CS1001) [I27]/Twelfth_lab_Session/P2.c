#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,max;
    printf("Enter the number of elements : ");
    scanf(" %d",&n);
    int *storer = (int *)malloc(n*sizeof(int));
    
    if (storer==NULL)
    {
        printf("Memory not allocated !");
        exit(1);
    }
    else
    {
        printf("Enter the elements : ");
        for (int i=0;i<n;i++)
            scanf(" %d",storer+i);
            
        printf("\n");
        max=*(storer);
        for (int i=0;i<n;i++)
        {
            if ((*(storer+i))>max)
                max=(*(storer+i));
        }
        
        printf("The Largest of the %d provided elements is : %d.\n",n,max);
    
    free(storer);
    
    storer=NULL;
    }
}