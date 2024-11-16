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

    int temp, min, min_index;

    for (j = 0; j < size; j++)
    {
        min = input_array[j];
        for (i = j; i < size; i++)
        {
            // Finding the minimum element of the unsorted Subarray.
            if (min > input_array[i])
            {
                min = input_array[i];
                min_index = i;
            }
        }

        // Swapping the minimum element with the first element.
        temp = input_array[j];
        input_array[j] = min;
        input_array[min_index] = temp;
    }

    // Printing the Sorted Array.
    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", input_array[i]);
}
