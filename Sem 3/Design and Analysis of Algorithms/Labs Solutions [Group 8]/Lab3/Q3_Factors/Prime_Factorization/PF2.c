#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct primeNode
{
	int prime;
	int power;
	struct primeNode* next;
};

int primeCheck(int a)
{
	for(int i = 2; i <= pow(a, 0.5); i++) {
		if(a % i == 0)
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
	
	struct primeNode* head = (struct primeNode *)malloc(sizeof(struct primeNode));
	head -> next = NULL;
	head -> prime = 2;
	head -> power = 0;

	int isPrime = 0;
	if(!primeCheck(n))
	{
		struct primeNode* temp = head;
		for(int i = 2; i <= n; i++) {
			isPrime = primeCheck(i);
			if(isPrime)	{
				if(n % i == 0) {
					temp->prime = i;
					temp->power = 0;
					
					for(int x = n; x % i == 0; x = x / i)
						(temp->power)++;
					
					struct primeNode* temp2 = (struct primeNode*)malloc(sizeof(struct primeNode));
					temp2 -> prime = 1;
					temp2 -> power = 0;
					temp2 -> next = NULL;
					temp -> next = temp2;
					temp = temp -> next;
				}	
			}
		}
		
		temp = head;
		while (temp -> next != NULL) {
			printf("%d pow %d \n", temp -> prime, temp -> power);
			temp = temp -> next;
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

// Time Complexity = O(n * root(n))
// Reason : Nested Loops





