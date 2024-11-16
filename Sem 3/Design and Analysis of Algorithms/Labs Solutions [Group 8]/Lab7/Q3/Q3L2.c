#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_JOBS 1000
#define MAX_MACHINES 100


void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


int main() {
    int n, m;
    int job_times[MAX_JOBS];
    int machines[MAX_MACHINES] = {0};
    int assignments[MAX_JOBS];

    // Seed the random number generator
    srand(time(NULL));

    printf("Enter the number of jobs: ");
    scanf(" %d", &n);
    printf("Enter the number of machines: ");
    scanf(" %d", &m);

    // Generate random job times
    for (int i = 0; i < n; i++)
        job_times[i] = rand() % 100 + 1;


    time_t start, end;
    double elapsed;

    time(&start);

    printf("Job times: ");
    for (int i = 0; i < n; i++)
        printf("%d ", job_times[i]);

    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (job_times[i] < job_times[j]) {
                int temp = job_times[i];
                job_times[i] = job_times[j];
                job_times[j] = temp;
            }
        }
    }

    // Assign jobs to machines
    for (int i = 0; i < n; i++) {
        int machine_index;
        if ((i / m) % 2 == 0) // Straight order
            machine_index = i % m;
        else // Reverse order
            machine_index = m - 1 - (i % m);
        
        machines[machine_index] += job_times[i];
    }

    // Print job assignments
    for (int i = 0; i < m; i++) {
        printf("Machine %d: ", i + 1);
        for (int j = 0; j < n; j++) 
            if (assignments[j] == i)
                printf("%d ", job_times[j]);

        printf("\n");
    }

    // Print load on each machine
    printf("Load on each machine:\n");
    for (int i = 0; i < m; i++)
        printf("Machine %d: %d\n", i + 1, machines[i]);


    time(&end);

	elapsed = difftime(end, start);
    printf("Elapsed time: %.f seconds\n", elapsed);

    return 0;
}