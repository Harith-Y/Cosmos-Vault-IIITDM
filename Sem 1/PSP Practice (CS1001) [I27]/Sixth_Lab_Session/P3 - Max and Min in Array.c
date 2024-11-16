#include<stdio.h>
void main()
{
    
    int n,i,max,min;
    printf("Please enter the number of elements in the Array : ");
    scanf("%d",&n);
    int a[n];
    
    for (i=0;i<n;i++)
    {
        //printf("Please enter the Element %d : ",i+1);
        scanf(" %d",&a[i]);
    }

    for (i=0;i<n;i++)
    {
        if (max<a[i])
            max=a[i];
    }
    
    for (i=0;i<n;i++)
    {
        min=a[0];
        if (min>a[i])
            min=a[i];
    }
    
    printf("%d - %d = %d\n",max,min,max-min);
    

}