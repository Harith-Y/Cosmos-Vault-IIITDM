#include<stdio.h>
struct Studentinfo
{
    int rollno,age;
    char name[100];
} student[5];
void main()
{
    int i;
    for (i=0;i<5;i++)
    {
        printf("Enter Roll Number of Student %d : ",i+1);
        scanf("%d",&student[i].rollno);
        printf("Enter Name of Student %d : ",i+1);
        scanf("%s",student[i].name);
        printf("Enter Age of Student %d : ",i+1);
        scanf("%d",&student[i].age);
    }
    printf("\nDetails of Student having Roll Number 2 : \n");
    printf("Roll Number : 2 \nName : %s \nAge : %d\n",student[1].name,student[1].age);
    
    
}