#include<stdio.h>
struct Employeedata
{
    int id,basic_pay,allowances,deductions;
} emp[1000];
void main()
{
    int n,i;
    printf("Please enter the number of employees : ");
    scanf(" %d",&n);
    
    int Net_Pay[n];
    
    for (i=0;i<n;i++)
    {
        printf("Please enter the ID of Employee %d : ", i+1);
        scanf(" %d",&emp[i].id);
        printf("Please enter the Basic Pay amount of Employee %d : ", i+1);
        scanf(" %d",&emp[i].basic_pay);
        printf("Please enter the Allowance of Employee %d : ", i+1);
        scanf(" %d",&emp[i].allowances);
        printf("Please enter the Deduction of Employee %d : ", i+1);
        scanf(" %d",&emp[i].deductions);
        Net_Pay[i]=emp[i].basic_pay + emp[i].allowances - emp[i].deductions;
        printf("\n");
    }
    
    printf("\n");
    
    for (i=0;i<n;i++)
    {
        printf("Salary of Employee ID '%d' is %d.\n", emp[i].id, Net_Pay[i]);   
    }
}