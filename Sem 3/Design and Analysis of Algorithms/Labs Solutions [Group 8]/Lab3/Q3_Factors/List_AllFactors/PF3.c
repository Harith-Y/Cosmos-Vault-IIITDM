#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
	clock_t start_time, end_time;
    double time_taken;
    start_time = clock();
    
	int n;
	scanf("%d", &n);
	

	for(int i = 1; i <= n; i++) {
		if(n % i == 0)
			printf("%d ", i);
	}
	
	printf("\n");
	
	end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    
	return 0;
}

// Time Complexity = O(n)
// Reason : Single for loop running from 1 to n

