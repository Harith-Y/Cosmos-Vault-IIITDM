#include <stdio.h>
#include <stdlib.h>

int linear_search(int a[], int n, int d)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == d)
            return i;
    }
    return -1;
}

int main()
{
    // Basic Stuff
    int size, i, j, data;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int input_array[size];
    printf("Enter the elements : ");

    // Taking input from the user and storing them index by index into the input array.
    for (i = 0; i < size; i++)
        scanf(" %d", &input_array[i]);

    printf("Enter the element you want to search : ");
    scanf(" %d", &data);

    int index = linear_search(input_array, size, data);

    if (index == -1)
        printf("Element does not exist in the Given Array !");
    else
        printf("The Given Data is in position %d", index + 1);
}