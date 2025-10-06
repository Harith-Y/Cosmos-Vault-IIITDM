// GROUP-8 1ST QUESTION THIRD LOGIC
#include<stdio.h>
#include<time.h>

void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int start, int end)
{
    int pivotIndex = (start + end) / 2;
    
    swap(&a[pivotIndex], &a[end]);
    pivotIndex = end;
    
    int i = start;
    int j = start;
    
    while (j < end)
    {
        if (a[j] <= a[pivotIndex])
        {
            swap(&a[i], &a[j]);
            i++;
        }
        j++;
    }
    
    swap(&a[i], &a[pivotIndex]);
    
    return i;
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
    int a[11] = {11, 9, 27, 69, 420, 35, 88, 1, 98, 8, 788};
    
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
	double time=((double) t) / CLOCKS_PER_SEC;
	printf("%f\n",time);
    
    return 0;
}

