#include<stdio.h>
void main()
{
    
    int i,j,c,r,x;
    printf("Enter the number of rows and the number of columns : ");
    scanf(" %d %d",&r,&c);
    // printf("Enter the number of columns : ");
    // scanf(" %d",&c);
    int a[r][c];
    
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            printf("Please enter the (%d,%d) element of the matrix : ",i+1,j+1);
            scanf(" %d",&a[i][j]);
        }
        
    }
    
    x=a[0][0];
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            if (x<a[i][j])
                x=a[i][j];
        }
    }
    
    printf("The largest element in the given matrix is : %d.\n", x);
    
    
    
    
}