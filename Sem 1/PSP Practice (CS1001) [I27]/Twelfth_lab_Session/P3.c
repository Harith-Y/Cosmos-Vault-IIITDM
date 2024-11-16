#include<stdio.h>
#include<stdlib.h>
void main()
{
    
    int row,column,n,temp;
    int choice;
    printf("Press 1 to Add two Matrices and Press 2 to Transpose a Matrix : ");
    scanf(" %d",&choice);
    printf("\n");
    switch(choice)
    {
        case 2:
            printf("Enter the number of rows of the matrix : ");
            scanf(" %d",&row);
            printf("Enter the number of columns of the matrix : ");
            scanf(" %d",&column);
            printf("\n");
            n=row*column;
            
            int *matrix = (int *)malloc(n*sizeof(int));
        
            if (matrix==NULL)
            {
                printf("Memory not allocated !");
                exit(1);
            }
            else
            {
                printf("Enter the elements of the matrix : \n");
                for (int i=0;i<n;i++)
                    scanf(" %d",matrix+i);
                
                temp=row;
                row=column;
                column=temp;
                printf("\n");
                printf("The Transpose of the given matrix is : \n");
                for (int i=0;i<row;i++)
                {    
                    for (int j=0;j<column;j++)
                    {
                        printf("%d ",*(matrix+(i)+(row*j)) );
                        if (j==column-1)
                            printf("\n");
                    }
                }
                
            free(matrix);
            matrix=NULL;
            
            }
            break;
            
        case 1:
            
            printf("Enter the number of rows of the matrices : ");
            scanf(" %d",&row);
            printf("Enter the number of columns of the matrices : ");
            scanf(" %d",&column);
            printf("\n");
            n=row*column;
            
            int *matrix1 = (int *)malloc(n*sizeof(int));
            int *matrix2 = (int *)malloc(n*sizeof(int));
        
            if ((matrix1==NULL)||(matrix2==NULL))
            {
                printf("Memory not allocated !");
                exit(1);
            }
            else
            {
                printf("Enter the elements of the matrix 1 : \n");
                for (int i=0;i<n;i++)
                    scanf(" %d",matrix1+i);
                printf("Enter the elements of the matrix 2 : \n");
                for (int i=0;i<n;i++)
                    scanf(" %d",matrix2+i);
                printf("\n");
                printf("The Sum of the given matrices is : \n");
                for (int i=0;i<row;i++)
                {    
                    for (int j=0;j<column;j++)
                    {
                        printf("%d ",(*(matrix1+(i*column)+(j)))+(*(matrix2+(i*column)+(j))));
                        if (j==column-1)
                            printf("\n");
                    }
                }
                
            free(matrix1); free(matrix2);
            matrix1=NULL; matrix2=NULL;
            
            }
            break;
            
        default:
            printf("Invalid Choice !");
    }
}