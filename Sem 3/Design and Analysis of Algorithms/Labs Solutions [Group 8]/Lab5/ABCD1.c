#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (1 << 15)  // 2^15 (left shift 1 bit by 15)
#define LEAF_SIZE (1 << 10)   // 2^10 (left shift 1 bit by 10)

void swap(int *a, int *b) // normal swap using temp variable
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generateRandomArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = i;  // Fill array with numbers 0 to size-1
    }
    
    // Fisher-Yates shuffle
    for (int i = size - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

void heapify(int arr[], int n, int i) 
{
    int largest = i; // parent element assumed to be the largest
    int left = 2 * i + 1; // by math, left child is 2i + 1
    int right = 2 * i + 2; // similarly, right child is 2i + 2

    if (left < n && arr[left] > arr[largest])
    {
        largest = left; // if left is less than n (should be less than the size of the array) and if the left child is greater than its parent, swap parent and left (hence, largest and left). make left the largest element
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right; // if right is less than n (should be less than the size of the array) and if the right child is greater than its parent, swap parent and right (hence, largest and right). make right the largest element
    }

    if (largest != i) // if largest has been changed, do the swap. after the swap, heapify so that the heap condition is satisfied for the changed tree. 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i); // heapify all the nodes other than the leaf nodes (leaves dont have children)
    }

    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]); // swap the root with the right and bottommost leaf
        heapify(arr, i, 0); // heapify at the root.
    } // in the next iteration, the swapped right most element (the highest element) will be ignored - its been sorted
}

void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1; // size of the left array 
    int n2 = right - mid; // size of the right array
    int L[n1], R[n2]; // array declared 

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i]; // left array initialized with values (from left to left + n1)
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j]; // right array initialized with values (from mid + 1 to mid + 1 + n2)
    }

    i = 0; // to iterate thru the left array
    j = 0; // to iterate thru the right array
    k = left;

    while (i < n1 && j < n2) // until one of i or j exceeds their respective array's size, run the loop
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i]; // if L[i] < R[j], add it to the sorted array first
            i++; // increment i value
        } 
        else 
        {
            arr[k] = R[j]; // if R[i] < L[j], add it to the sorted array first
            j++; // increment j value
        }
        
        k++; // the sorted array's size increases anyways
    }

    while (i < n1) // after the first while loop, add the remaining elements been left out in the same order as in the L array (since they are all sorted). 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) // after the first while loop, add the remaining elements been left out in the same order as in the R array (since they are all sorted). 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void recursiveHybridSort(int arr[], int left, int right) // 2 way Merge Sort - divide until leaf array's size is 1024. if 1024, heapsort that array. merge the 2 children arrays - into 1 2048 array. keep doing this until the original array is sorted
{
    if (right - left + 1 > LEAF_SIZE)  // checks if the size of the block passed is greater than the leaf size. if yes, divide the array further into right and left (half its size). this happens until the array's size is 1024
    {
        int mid = left + (right - left) / 2; // mid value will be left + (right - left) / 2 . we add left because it defines where the block starts
        
        recursiveHybridSort(arr, left, mid); // divide for left
        recursiveHybridSort(arr, mid + 1, right); // divide for right
        merge(arr, left, mid, right); // merges once the left and right fellows are sorted by heapsort
    } 
    else 
    {
        heapSort(arr + left, right - left + 1); // heapSort the array from left, with size right - left + 1 - this happens only if the size is LEAF_SIZE or lesser.
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    generateRandomArray(arr, ARRAY_SIZE);

    printf("Array size: %d\n", ARRAY_SIZE);
    printf("Elements before sorting: \n");
    printArray(arr, ARRAY_SIZE);

    recursiveHybridSort(arr, 0, ARRAY_SIZE - 1);
    printf("\n \n \n \n");
    printf("Elements after sorting: \n");
    printArray(arr, ARRAY_SIZE);

    return 0;
}