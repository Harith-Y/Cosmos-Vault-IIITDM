#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Basic Stuff
    int size, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int input_array[size];
    printf("Enter the elements : ");

    // Taking input from the user and storing them index by index into the input array.
    for (i = 0; i < size; i++)
        scanf(" %d", &input_array[i]);

    for (i = 1; i < size; i++)
    {
        int temp = input_array[i];
        j = i;
        while ((temp < input_array[j - 1]) && (j > 0))
        {
            input_array[j] = input_array[j - 1];
            input_array[j - 1] = temp;
            j--;
        }
    }

    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", input_array[i]);
}