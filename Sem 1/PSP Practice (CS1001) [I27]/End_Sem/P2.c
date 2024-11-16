#include<stdio.h>
#include<string.h>


struct Employee
{
    int id;
    char name[1000];
    int salary;
    char letter;
    int count;

} emp[1000];


int fun1(char[]);
int fun2(int,char);
void fun3(int, char[], int, char, int);


void main()
{
    int n;
    scanf(" %d",&n);

    for (int i=0;i<n;i++)
    {
        scanf(" %d",&emp[i].id);
        scanf("%s",emp[i].name);
        scanf(" %d",&emp[i].salary);
    }

    int maxsalary=emp[0].salary;
    for (int i=0;i<n;i++)
    {
        if (emp[i].salary>maxsalary)
            maxsalary=emp[i].salary;
    }

    int mem;
    for (mem=0;mem<n;mem++)
    {
        if (emp[mem].salary==maxsalary)
            break;
    }

    for (int j=0;j<n;j++)
    {
        emp[j].letter = fun1(emp[j].name);
        emp[j].count = fun2(n,emp[j].letter);
    }

    fun3(emp[mem].id, emp[mem].name, emp[mem].salary, emp[mem].letter, emp[mem].count);

}

int fun1(char empname[])
{
    int maxletter=empname[0];

    for (int i=0;i<strlen(empname);i++)
    {
        if (empname[i]>maxletter)
            maxletter = empname[i];
    }
    
    return maxletter;
}

int fun2(int total, char maxletter)
{
    int COUNT=0;
    
    for (int i=0;i<total;i++)
    {
        if (emp[i].name[0] == maxletter)
            COUNT++;
    }

    return COUNT;
}

void fun3(int empid, char empname[], int empsalary, char empletter, int empcount)
{
    printf("\n\n%d\n%s\n%d\n%c\n%d\n",empid,empname,empsalary,empletter,empcount);
}
