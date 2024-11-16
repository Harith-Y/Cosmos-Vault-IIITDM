#include <stdio.h>
#include <stdlib.h>

int binary_search(int original[], int n, int d)
{
    int sorted[n];
    for (int i = 0; i < n; i++)
        sorted[i] = original[i];

    // Bubble Sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    int l = 0;
    int r = n - 1;
    while (1)
    {
        int mid = (l + r) / 2;

        if (d > sorted[mid])
            l = mid + 1;

        else if (d < sorted[mid])
            r = mid - 1;

        else
        {
            l = mid;
            r = mid;
        }

        if (l > r)
            return 0;

        else if (l == r)
            break;
    }

    int index;
    for (index = 0; index < n; index++)
    {
        if (original[index] == sorted[l])
            break;
    }

    return index;
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

    int index = binary_search(input_array, size, data);

    if (index == 0)
        printf("Element does not exist in the Given Array !");
    else
        printf("The Given Data is in position %d", index + 1);
}