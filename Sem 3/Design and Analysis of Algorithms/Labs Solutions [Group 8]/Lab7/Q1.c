#include <stdio.h>
#include<stdlib.h>
#include<time.h>
struct Job
{
    int start;
    int finish;
};

void merge(struct Job Jobs[], int low, int mid, int high)
{
    int Lsize = mid - low + 1;
    int Rsize = high - mid;
    struct Job left[Lsize], right[Rsize];

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < Lsize; i++)
    {
        left[i] = Jobs[low + i];
    }
    for (int i = 0; i < Rsize; i++)
    {
        right[i] = Jobs[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    // Merge the temporary arrays back into Jobs[]
    while (i < Lsize && j < Rsize)
    {
        if (left[i].finish <= right[j].finish)  // Use <= to handle equal finish times
        {
            Jobs[k] = left[i];
            i++;
        }
        else
        {
            Jobs[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < Lsize)
    {
        Jobs[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < Rsize)
    {
        Jobs[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(struct Job Jobs[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(Jobs, low, mid);
        mergeSort(Jobs, mid + 1, high);
        merge(Jobs, low, mid, high);
    }
}

void printStruct(struct Job Jobs[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Job : %d - Start Time : %d - End Time : %d\n",i+1 , Jobs[i].start, Jobs[i].finish);
    }
    printf("\n");
}

int main()
{
    int n;
    srand(time(0));
    n=rand()%20+1;
    struct Job Jobs[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        Jobs[i].start = rand() % 10 + 1;
        Jobs[i].finish = Jobs[i].start+ rand() % 10 + 1;
    }

    printf("Unsorted Jobs:\n");
    printStruct(Jobs, n);

    mergeSort(Jobs, 0, n - 1);

    printf("Sorted Jobs:\n");
    printStruct(Jobs, n);

	struct Job Greedy[n];
	
	Greedy[0].start = Jobs[0].start;
	Greedy[0].finish = Jobs[0].finish;
	int k = 0;
	for(int i = 1; i < n; i++)
	{
		if(Greedy[k].finish <= Jobs[i].start)
		{
			k++;
			Greedy[k].start = Jobs[i].start;
			Greedy[k].finish = Jobs[i].finish;
		}
	}
	printStruct(Greedy, k + 1);

    return 0;
}

