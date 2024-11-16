#include<stdio.h>
void main()
{
    int i,j,k,n,ra,ca,cb;
    printf("Please enter the number of rows and columns of the First matrix, and the number of columns of the Second matrix : ");
    scanf("%d %d %d",&ra,&ca,&cb);
    int a[ra][ca],b[ca][cb],prod[ra][cb];
    
    for (i=0;i<ra;i++)
    {
        for (j=0;j<ca;j++)
        {
            printf("Please enter the (%d,%d) element of First matrix : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
        
    }
    
    for (i=0;i<ca;i++)
    {
        for (j=0;j<cb;j++)
        {
            printf("Please enter the (%d,%d) element of Second matrix : ",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
        
    }
    
    for (i=0;i<ra;i++)
    {
        for (j=0;j<cb;j++)
        {
            prod[i][j]=0;
            for (k=0;k<ca;k++)
            {
                prod[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    
    for (i=0;i<ra;i++)
    {
        for (j=0;j<cb;++j)
        {
            printf("%d ",prod[i][j]);
            if (j==(cb-1))
                printf("\n");
        }
    }
    
    
}