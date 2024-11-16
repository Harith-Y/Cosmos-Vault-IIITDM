#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 32768
#define LEAF_SIZE 1024
#define NUM_LEAVES (ARRAY_SIZE / LEAF_SIZE)

int comparison_count = 0; // Global counter for comparisons

// Function prototypes
void mergeSort(int sa[][LEAF_SIZE], int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
int findMax(int arrays[NUM_LEAVES][LEAF_SIZE], int sizes[NUM_LEAVES]);

int main() {
    int arr[ARRAY_SIZE];
    int sortedLeaves[NUM_LEAVES][LEAF_SIZE];
    int sizes[NUM_LEAVES];

    // Seed the random number generator
    srand(time(NULL));

    // A) Create a random integer array of size 32768
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100000; // Random integers between 0 and 99999
    }

    // B) Perform 2-Way Merge Sort until input size is reduced to 1024
    mergeSort(sortedLeaves, arr, 0, ARRAY_SIZE - 1);

    // C) Initialize sizes for all leaves to 1023 (heap sort starts with 1024 elements but we decrement on each max extraction)
    for (int i = 0; i < NUM_LEAVES; i++) {
        sizes[i] = LEAF_SIZE - 1; // Initially, all arrays have 1024 elements, index goes from 0 to 1023
    }

    // D) Find MAX out of 32 arrays and output all elements in sorted order
    printf("Sorted elements:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int max = findMax(sortedLeaves, sizes);
        printf("%d ", max);
    }
    printf("\nTotal comparisons: %d\n", comparison_count);
    return 0;
}

// Merge Sort functions (cutoff at LEAF_SIZE)
void mergeSort(int sortedLeaves[NUM_LEAVES][LEAF_SIZE], int arr[], int l, int r) {
    if (r - l + 1 <= LEAF_SIZE) {
        // Copy the elements into the corresponding leaf
        int leafIndex = l / LEAF_SIZE;
        for (int i = 0; i < LEAF_SIZE; i++) {
            sortedLeaves[leafIndex][i] = arr[l + i];
        }
        // C) Perform Heap sort at each leaf node
        heapSort(sortedLeaves[leafIndex], LEAF_SIZE);
        return;
    }

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(sortedLeaves, arr, l, m);
        mergeSort(sortedLeaves, arr, m + 1, r);
    }
}

// Heap Sort functions
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Compare left child
    comparison_count++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Compare right child
    comparison_count++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Swap and continue heapifying if necessary
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Find MAX out of 32 arrays
int findMax(int arrays[NUM_LEAVES][LEAF_SIZE], int sizes[NUM_LEAVES]) {
    int max = -1;
    int maxIndex = -1;

    // Search for the maximum element among the 32 arrays
    for (int i = 0; i < NUM_LEAVES; i++) {
        if (sizes[i] >= 0 && arrays[i][sizes[i]] > max) {
            max = arrays[i][sizes[i]];
            maxIndex = i;
        }
    }

    // Remove the maximum element from the corresponding array
    if (maxIndex != -1) {
        sizes[maxIndex]--;
    }

    return max;
}
