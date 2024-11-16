#include <stdio.h>
#include <stdlib.h>

// Power function for logic of a part of the Code.
int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}

int main()
{
    // Basic Stuff
    int size, i, j, div, temp, pass, multiplier = 10, factor;
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

    // Finding the number of digits of the largest element of the Input Elements.
    int num_of_digits = 0;
    for (int num = max; num != 0; num /= 10)
        num_of_digits++;

    int bucket_array[size], main_array[size], digit_array[size];

    // initialised and equalized them to input array for future purposes
    for (i = 0; i < size; i++)
    {
        bucket_array[i] = input_array[i];
        main_array[i] = input_array[i];
    }

    // Number of Passes the code needs to go through, depends on the number of digits
    for (pass = 0; pass < num_of_digits; pass++)
    {
        j = 0;

        // Storing the individual elements pass by pass into the digit array.
        factor = power(multiplier, pass);
        for (i = 0; i < size; i++)
            digit_array[i] = bucket_array[i] / factor;

        // Filling up bucket array (future main array) in such a way that remainders are in ascending order (First 0, so on until Last 9)
        for (div = 0; div < 10; div++)
        {

            for (i = 0; i < size; i++)
            {
                if (digit_array[i] % 10 == div)
                {
                    bucket_array[j] = main_array[i];
                    j++;
                }
            }
        }

        // Digit array, because we follow logic of dividing by 10 power x and then taking remainder by 10 to find individual digits.
        //  Main array just acts like a duplicate bucket array.
        for (i = 0; i < size; i++)
        {
            digit_array[i] = bucket_array[i];
            main_array[i] = bucket_array[i];
        }
    }

    // Printing the Sorted Array.
    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", main_array[i]);
}