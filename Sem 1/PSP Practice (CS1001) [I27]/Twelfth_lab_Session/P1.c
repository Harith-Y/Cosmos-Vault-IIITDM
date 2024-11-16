#include<stdio.h>
#include<stdlib.h>
void main()
{
    
    int n;
    printf("Enter the number of members : ");
    scanf(" %d",&n);
    printf("\n");
    float *height = (float *)malloc(n*sizeof(float));
    float *weight = (float *)malloc(n*sizeof(float));
    
    if ((height==NULL)||(weight==NULL))
    {
        printf("Memory not allocated !");
        exit(1);
    }
    else
    {
        for (int i=0;i<n;i++)
        {
            printf("Enter the weight of member %d : ",i+1);
            scanf(" %f",weight+i);
            printf("Enter the height of member %d : ",i+1);
            scanf(" %f",height+i);
        }
        printf("\n");
        for (int i=0;i<n;i++)
            printf("BMI of member %d : %.3f\n",i+1,(*(weight+i))/(*(height+i)));
    
    free(height);
    free(weight);
    
    height=NULL;
    weight=NULL;
    
    }

}