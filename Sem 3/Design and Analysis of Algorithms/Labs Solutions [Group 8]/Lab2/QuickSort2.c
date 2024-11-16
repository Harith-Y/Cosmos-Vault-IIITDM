// GROUP-8 1ST QUESTION SECOND LOGIC
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
    int pivotIndex = end; 
    int i = start - 1; 
	int j = start;
	
    while (j < end)
    {
        if (a[j] <= a[pivotIndex])
        {
            i++;
            swap(&a[i], &a[j]);
        }
        j++;
    }
    
    swap(&a[i + 1], &a[end]);
    pivotIndex = i + 1;
    
    return pivotIndex;
}

void quickSort(int a[], int low, int high)
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
    int a[11] = {5, 8, 3, 2, 7, 420, 69, 1, 15, 17, 243};
    
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
  
    printf("\n");
     
    clock_t t;
	t = clock();
     
    quickSort(a, 0, size - 1);
 
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);

    printf("\n");
    
    t = clock() - t;
	double time = ((double) t) / CLOCKS_PER_SEC;
	printf("%f\n", time);
    
    return 0;
}

