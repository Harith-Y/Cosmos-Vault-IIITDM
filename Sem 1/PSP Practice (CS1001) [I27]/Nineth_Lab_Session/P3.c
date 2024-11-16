#include <stdio.h>
int subset_fn(int,int,int,int);

void main() 
{
    int m,n,i;
    printf("Enter the size of the first set : ");
    scanf(" %d",&m);
    int a[m];
    printf("Enter elements of the first set : ");
    for (i=0;i<m;i++) 
        scanf(" %d",&a[i]);

    printf("Enter the size of the Second set : ");
    scanf(" %d",&n);
    int b[n];
    printf("Enter elements of the Second set : ");
    for (i=0;i<n;i++)
        scanf(" %d",&b[i]);


    if (subset_fn(m,n,a,b))
        printf("Second set is a subset of First set ");
    else
        printf("Second set is not a subset of First set ");

}

int subset_fn(int m,int n,int a[],int b[]) 
{
    int i,j;
    for (i=0;i<n;i++) 
    {
        for (j=0;j<m;j++) 
        {
            if (b[i]==a[j])
                break;
        }
        if (j==m)
            return 0;
    }
    return 1;
}
