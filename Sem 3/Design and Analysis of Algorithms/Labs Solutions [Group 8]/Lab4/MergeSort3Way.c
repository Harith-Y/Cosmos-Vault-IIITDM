//Group 8

#include <stdio.h>
#include <stdlib.h>

//Pass by Pass execution
void Merge(int arr[], int l, int m1, int m2, int h) {
    int size1, size2, size3;
    size1 = m1 - l + 1;
    size2 = m2 - m1;
    size3 = h - m2;
    
    int a[size1], b[size2], c[size3];
    
    for (int i = 0; i < size1; i++)
        a[i] = arr[l + i];
    for (int i = 0; i < size2; i++)
        b[i] = arr[m1 + 1 + i]; 
    for (int i = 0; i < size3; i++)
        c[i] = arr[m2 + 1 + i];
    
    int i = 0, j = 0, k = 0, m = l;
    
    while ((i < size1) && (j < size2) && (k < size3)) {
        if ((a[i] <= b[j]) && (a[i] <= c[k])) {
            arr[m] = a[i];
            i++;
        }
        
        else if ((b[j] <= a[i]) && (b[j] <= c[k])) {
            arr[m] = b[j];
            j++;
        }
        
        else {
            arr[m] = c[k];
            k++;
        }
        m++;
    }
    
    
    while ((i < size1) && (j < size2)) {
    	if (a[i] <= b[j]) {
        	arr[m] = a[i];
        	i++;
        	m++;
        }
        else {
        	arr[m] = b[j];
    		j++;
    		m++;
    	}
    }
    while ((j < size2) && (k < size3)) {
    	if (b[j] <= c[k]) {
        	arr[m] = b[j];
        	j++;
        	m++;
        }
        else {
        	arr[m] = c[k];
        	k++;
        	m++;
        }
    }
    while ((i < size1) && (k < size3)) {
        if (a[i] <= c[k]) {
        	arr[m] = a[i];
        	i++;
        	m++;
        }
        else {
        	arr[m] = c[k];
        	k++;
        	m++;
        }
    }
    
    
    while (i < size1) {
        arr[m] = a[i];
        i++;
        m++;
    }
    while (j < size2) {
        arr[m] = b[j];
        j++;
        m++;
    }
    while (k < size3) {
        arr[m] = c[k];
        k++;
        m++;
    }
}

//Merge Sorting
void Merge_Sort(int a[], int l, int h) {
    
    if (l < h) {
        int m1 = (l + h) / 3;
        int m2 = l + (2 * (h - l)) / 3;
        Merge_Sort(a, l, m1);
        Merge_Sort(a, m1+1, m2);
        Merge_Sort(a, m2+1, h);
        Merge(a, l, m1, m2, h);
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
