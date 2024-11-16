// GROUP-8 1ST QUESTION FIRST LOGIC
#include<stdio.h>
#include<time.h>

void swap (int *a, int *b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int a[], int start, int end)
{
	int pivotIndex = start;
	int i = start + 1, j = end;
	while (i < j)
	{
		while (a[i] <= a[pivotIndex])
			i++;
		
		while (a[j] > a[pivotIndex])
			j--;
		
		if(j <= i)
			swap(&a[j] , &a[pivotIndex]);

		else
			swap(&a[i], &a[j]);
	}
	
	pivotIndex = j;
	return pivotIndex;
}

void quickSort (int a[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(a, low, high);
		quickSort(a, low, pivot - 1);
		quickSort(a, pivot + 1, high);
	}
}

int main()
{
	int size = 11;
	int a[11] = {1, 5, 3, 4, 420, 2, 8, 69, 9, 10, 15};
	for(int i = 0; i != size; i++)
		printf("%d ", a[i]);

	printf("\n");
	
	clock_t t;
	t = clock();
	
	quickSort(a, 0, 10);
	
	for(int i = 0; i != size; i++)
		printf("%d ", a[i]);
	
	printf("\n");
	
	t = clock() - t;
	double time = ((double) t) / CLOCKS_PER_SEC;
	printf("%f\n", time);
}
