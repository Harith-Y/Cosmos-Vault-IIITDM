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

    // Finding out the largest element of the input array
    int max = input_array[0];
    for (i = 0; i < size; i++)
    {
        if (max < input_array[i])
            max = input_array[i];
    }

    // Initializing a new zero array
    int count_array[max + 1];
    for (i = 0; i < max + 1; i++)
        count_array[i] = 0;

    // Wherever you find the elements in the input array, according to that, 1 will be added to that corresponding index of count array.
    for (i = 0; i < size; i++)
        count_array[input_array[i]] = count_array[input_array[i]] + 1;

    // Modifying the count array by adding each element to its previous element.
    for (i = 1; i < max + 1; i++)
        count_array[i] += count_array[i - 1];

    // Entering the elements into a new Array.
    int sorted_array[size];
    for (i = size - 1; i > -1; i--)
    {
        count_array[input_array[i]] = (count_array[input_array[i]]) - 1;
        sorted_array[(count_array[input_array[i]])] = input_array[i];
    }

    // For Debugging, count array can be printed.
    // printf("Count Array : ");
    // for (int i = 0; i < max + 1; i++)
    //     printf("%d ", count_array[i]);
    // printf("\n");

    // Printing the Sorted Array.
    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", sorted_array[i]);

    return 0;
}