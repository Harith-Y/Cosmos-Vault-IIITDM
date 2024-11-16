#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // Basic Stuff
    int size, i, j, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int input_array[size];
    printf("Enter the elements : ");

    // Taking input from the user and storing them index by index into the input array.
    for (i = 0; i < size; i++)
        scanf(" %d", &input_array[i]);

    // Responsible for Passes
    for (i = 0; i < size - 1; i++)
    {
        // Seeing adjacent elements and swapping if the next element is greater than previous.
        for (j = 0; j < size; j++)
        {
            if (input_array[j] > input_array[j + 1])
                swap(&input_array[j], &input_array[j + 1]);
        }
    }

    // Printing the Sorted Array.
    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", input_array[i]);
}