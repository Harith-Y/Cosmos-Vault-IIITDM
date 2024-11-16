#include <stdio.h>
#include <math.h>
#include <time.h>

int primeCheck(int a)
{
	for (int i = 2; i <= pow(a, 0.5); i++)
	{
		if (a % i == 0)
			return 0;
	}
	
	return 1;
}

int main()
{
	clock_t start_time, end_time;
    double time_taken;
    start_time = clock();
    
	int n;
	scanf(" %d", &n);
	
	int isPrime = 0;
	if(!primeCheck(n))
	{
		for (int i = 2; i <= n; i++) {
			isPrime = primeCheck(i);
			
			if (isPrime) {
				if(n % i == 0)
					printf("%d ", i);
			}
		}
	}
	else
		printf("Entered a prime number \n");
	
	printf("\n");
	
	end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    
	return 0;
}

//Time Complexity = O(n * root(n))
//Reason: For each of the n iterations, checking if a number up to i is prime involves O(root(i)) operations.
