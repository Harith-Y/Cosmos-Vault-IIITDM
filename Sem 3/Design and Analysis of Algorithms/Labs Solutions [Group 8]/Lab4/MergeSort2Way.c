//Group 8

#include <stdio.h>
#include <stdlib.h>

//Pass by Pass execution
void Merge(int c[], int l, int m, int h) {
    int size1, size2;
    size1 = m - l + 1;
    size2 = h - m;
    
    int a[size1], b[size2];
    
    int i;
    for (i=0 ; i < size1; i++)
        a[i] = c[l + i];
    for (i=0 ; i < size1; i++)
        b[i] = c[m + 1 + i]; 
    
    int j = 0, k = l;
    i = 0;
    
    while ((i < size1) && (j < size2)) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            i++;
        }
        
        else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    
    while (i < size1) {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < size2) {
        c[k] = b[j];
        j++;
        k++;
    }
}

//Merge Sorting
void Merge_Sort(int a[], int l, int h) {
    
    if (l < h) {
        int m = (l + h) / 2;
        Merge_Sort(a, l, m);
        Merge_Sort(a, m+1, h);
        Merge(a, l, m, h);
    }
}

void main() {
    int size;
    printf("Please enter the number of elements to be sorted : ");
    scanf(" %d", &size);
    
    int input_array[size], sorted_array[size];
    
    printf("Please enter the elements : ");
    for (int i = 0; i < size; i++)
        scanf(" %d", &input_array[i]);
        
    //Copying the Input element into another Array
    for (int i = 0; i < size; i++)
        sorted_array[i] = input_array[i];
        
    Merge_Sort(sorted_array, 0, size - 1);
    
    printf("The elements in the sorted order are : ");
    for (int i = 0; i < size; i++)
        printf("%d ", sorted_array[i]);
        
    printf("\n");
}
