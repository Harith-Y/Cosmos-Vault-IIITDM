#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int low, int mid, int high)
{
	int lSize = mid - low + 1;
	int rSize = high - mid;
	int aLeft[lSize], aRight[rSize];
	
	for(int i = 0; i < lSize; i++)
	{
		aLeft[i] = arr[low + i];
	}
	for(int j = 0; j < rSize; j++)
	{
		aRight[j] = arr[mid + 1 + j];
	}
	
	int i = 0, j = 0, k = low;
	while(i < lSize && j < rSize)
	{
		if(aLeft[i] <= aRight[j])
		{
			arr[k++] = aLeft[i++];
		}
		else
		{
			arr[k++] = aRight[j++];
		}
	}
	
	while(i < lSize)
	{
		arr[k++] = aLeft[i++];
	}
	while(j < rSize)
	{
		arr[k++] = aRight[j++];
	} 
}

void mergeSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void generateRandomArray(int arr[], int n, int maxSize)
{
	for(int i = 0; i < n; i++)
	{
		arr[i] = rand() % maxSize + 1;
	}
}

int findMin(int kids[], int sticks[], int n)
{
	int minDiff = 0;
	for(int i = 0; i < n; i++)
	{
		minDiff += abs(kids[i] - sticks[i]);
	}
	
	return minDiff;
}

void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int n, maxSize;
	
	printf("Enter the number of kids and hockey sticks: ");
	scanf("%d", &n);
	
	printf("Enter the max size of kids and hockey sticks: ");
	scanf("%d", &maxSize);
	
	int kids[n], sticks[n];
	generateRandomArray(kids, n, maxSize);
	generateRandomArray(sticks, n, maxSize);
	
	printf("Kids: \n");
	printArray(kids, n);
	
	printf("Sticks: \n");
	printArray(sticks, n);
	
	mergeSort(kids, 0, n - 1);
	mergeSort(sticks, 0, n - 1);
	
	printf("Kids after sort: \n");
	printArray(kids, n);
	
	printf("Sticks after sort: \n");
	printArray(sticks, n);
	
	int diff = findMin(kids, sticks, n);
	printf("The minimum sum of differences using approach 1 is: %d \n", diff);
	
	return 0;
}

// Approach 1 - Sort the Sticks and Kids array in ascending order, and do abs(Sticks[i] - Kids[i]) for i in (1 to n)
