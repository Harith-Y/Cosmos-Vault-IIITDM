#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_JOBS 1000
#define MAX_MACHINES 100

// Function to find the machine with the minimum load
int find_min_load_machine(int machines[], int m) {
    int min_index = 0;
    for (int i = 1; i < m; i++) {
        if (machines[i] < machines[min_index])
            min_index = i;
    }
    return min_index;
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

    // Assign jobs to machines using a greedy strategy
    for (int i = 0; i < n; i++) {
        int min_machine = find_min_load_machine(machines, m);
        machines[min_machine] += job_times[i];
        assignments[i] = min_machine;
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