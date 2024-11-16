#include <stdio.h>
#include <string.h>
void func(int, int[], int);
int main()
{
    int no_of_q;
    printf("Enter the Total number of Questions : ");
    scanf("%d", &no_of_q);
    int question[no_of_q], q, k, Flag = 0;
    for (int i = 0; i < no_of_q; i++)
        question[i] = i + 1;
    printf("\nTotal Number of Questions left to be finished : %d \n", no_of_q);
    for (int i = 0; i < no_of_q; i++)
        printf("%d ", question[i]);
    printf("\n \n");

    int x = no_of_q;
    while (printf("Enter the Question number which you just finished (Enter 0 to Exit) : ") && scanf("%d", &q) && q != 0)
    {
        printf("\n");
        for (k = 0; (k < x) && (question[k] != q); k++)
        {
            Flag = 0;
        }
        if (question[k] == q)
            Flag = 1;

        if (q >= 1 && q <= no_of_q)
        {
            if (Flag == 1)
            {
                func(no_of_q, question, q);
                x--;
                printf("Questions left to be finished : %d\n", x);
                for (int i = 0; i < x; i++)
                    printf("%d ", question[i]);
                printf("\n \n");
            }
            else
            {
                printf("Question already finished.\n");
                printf("Questions left to be finished : %d\n", x);
                for (int i = 0; i < x; i++)
                    printf("%d ", question[i]);
                printf("\n \n");
            }
        }
        else
        {
            printf("No Question as such exists. \n \n");
            printf("Questions left to be finished : %d\n", x);
            for (int i = 0; i < x; i++)
                printf("%d ", question[i]);
            printf("\n \n");
        }

        if (x == 0)
            break;
    }
    printf("Exiting... \n \n");
}
void func(int qnos, int a[], int q)
{
    int l = qnos;
    for (int i = 0; i < l; i++)
    {
        if (a[i] == q)
        {
            a[i] = 0;
            for (int j = i; j < l - 1; j++)
                a[j] = a[j + 1];
            l--;
            i--;
        }
    }
}
