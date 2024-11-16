#include<stdio.h>
void main()
{
    int num,st,en,n,x;
    printf("Please enter the number : ");
    scanf(" %d",&num);
    printf("From where should the table start ? : ");
    scanf(" %d",&st);
    printf("And where should the table end ? : ");
    scanf(" %d",&en);
    
    if ((st<0) || (en<0))
        printf("Invalid Input ! Either one of them should be non-negative. \n");
    else
    {
        while (st<=en)
        {
            x=st*num;
            printf("%d * %d = %d \n",num,st,x);
            st=st+1;
        }
    }

    
}