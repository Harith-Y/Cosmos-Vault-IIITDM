#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void generateArray(int *arr, int n, int maxSize) {
	for (int i = 0; i < n; i++)
		arr[i] = rand() % maxSize + 1;
}

int findMin(int *kids, int *sticks, int n, int *visited) {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		int min = abs(kids[i] - sticks[0]);
		int visit = 0;
		for (int j = 1; j < n; j++) {
			if (visited[j] == 0 && abs(kids[i] - sticks[j]) < min) {
				min = abs(kids[i] - sticks[j]);
				visit = j;
			}
		}
		visited[visit] = 1;
		diff += min;
	}
	return diff;
}

void printArr(int *arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

int main() {
	int n, maxSize;
	printf("Enter the number of kids and sticks : ");
	scanf(" %d", &n);
	printf("Enter the number of kids and sticks : ");
	scanf(" %d", &maxSize);
	
	time_t start, end;
    double elapsed;

    // Record start time
    time(&start);
	
	int kids[n], sticks[n], visited[n];
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	
	generateArray(kids, n, maxSize);  
	generateArray(sticks, n, maxSize);
	printf("KIDS : ");
	printArr(kids, n);
	printf("STICKS : ");
	printArr(sticks, n);
	
	
	
	int mindiff = findMin(kids, sticks, n, visited);
	
	printf("\n\nThe minimum sum of differences using approach two is : %d\n", mindiff);
	
	time(&end);

	elapsed = difftime(end, start);
    printf("Elapsed time: %.f seconds\n", elapsed);
	
	return 0;
}

