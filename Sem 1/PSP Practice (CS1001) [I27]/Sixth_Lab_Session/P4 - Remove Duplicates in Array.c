#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Please enter the number of elements in the Array : ");
    scanf(" %d",&n);
    int a[n],b[n];
    
    for (i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
        
    }
    a[n]=b[n];
    
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (a[i]==a[j])
            {
                for (k=j;k<n;k++)
                {
                    a[k]=a[k+1];
                }
                n=n-1;
                j=j-1;
            }
        }
        
    }
    
    for (i=0;i<n;i++)
        printf("%d ", a[i]);
    
}