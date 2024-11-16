#include <stdio.h>
#include <stdlib.h>

//Swapping two elements
void swap (int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Pass by Pass Execution
int partition (int a[], int l, int h) {
    int pivot = a[l];
    int i = l, j = h;
    
    while (i < j) {
        while ((a[i] <= pivot) && (i <= h - 1))
            i++;
        while ((a[j] > pivot) && (j >= l + 1))
            j--;
            
        if (i < j)
            swap(&a[i],&a[j]);
        }
    swap(&a[l], &a[j]);
    return j;
}

//Quick Sorting
void QuickSort(int a[], int l, int h) {
    int pivot;
    if (l < h) {
        p = partition(a, l, h);
        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, h);
    }
}

void main() {
    int size;
    printf("Please enter the number of elements to be sorted : ");
    scanf(" %d", &size);
    
    int input_array[size], sorted_array[size];;
    int i;
    printf("Please enter the elements : ");
    for (i = 0 ; i < size ; i++)
        scanf(" %d", &input_array[i]);
        
    //Copying the input array into another array which is going to be sorted
    for (i = 0 ; i < size ; i++)
        sorted_array[i] = input_array[i];
    
    QuickSort(sorted_array, 0, size - 1);
    
    printf("The Elements in sorted Order are : ");
    for (i = 0; i < size; i++)
        printf("%d ",sorted_array[i]);

}