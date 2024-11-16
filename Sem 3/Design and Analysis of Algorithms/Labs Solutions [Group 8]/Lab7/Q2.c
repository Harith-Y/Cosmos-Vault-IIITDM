#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
    int id;
    int deadline;
    int timetaken;
    int start;
    int end;
    int late;
} jobs;

void merge(jobs *arr, int l, int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    jobs L[n1], R[n2];
    for(int i=0; i<n1; i++)
    {
        L[i]=arr[l+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i]=arr[m+1+i];
    }
    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i].deadline<=R[j].deadline)
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(jobs *arr, int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void randcreate(jobs *arr, int n)
{
    srand(time(0));
    for(int i=0; i<n; i++)
    {
        arr[i].id=i+1;
        arr[i].deadline=rand()%10+1;
        arr[i].timetaken=rand()%arr[i].deadline+1;
    }
}

void schedule(jobs *arr, int n)
{
    mergesort(arr, 0, n-1);
    int time=0;
    for(int i=0; i<n; i++)
    {
        arr[i].start=time;
        time+=arr[i].timetaken;
        arr[i].end=time;
        if(arr[i].end>arr[i].deadline)
        {
            arr[i].late=arr[i].end-arr[i].deadline;
        }
        else
        {
            arr[i].late=0;
        }

    }
}

void print(jobs *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Job %d: Deadline: %d, Time taken: %d, Start: %d, End: %d, Late: %d\n", arr[i].id, arr[i].deadline, arr[i].timetaken, arr[i].start, arr[i].end, arr[i].late);
    }
}

void printbefore(jobs *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Job %d: Deadline: %d, Time taken: %d\n", arr[i].id, arr[i].deadline, arr[i].timetaken);
    }
}

void main()
{
    int n;
    // generating random number of jobs by seeding the random number generator  
    srand(time(0));
    n=rand()%20+1;
    jobs arr[n];
    // generaring random deadlines and time taken
    randcreate(arr, n);
    //printing instance genrated
    printf("Instance generated\n\n");
    printbefore(arr, n);
    // sorting the jobs based on deadlines
    schedule(arr, n);
    printf("\n\nInstance after scheduling\n\n");
    print(arr, n);
}

