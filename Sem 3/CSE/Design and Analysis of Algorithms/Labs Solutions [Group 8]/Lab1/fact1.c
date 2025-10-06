#include <stdio.h>

// Driver Code
void main() {
	int t; //Testcases
	scanf(" %d", &t);
	long long int result[t];
	
	for (int k = 0; k < t; k++) {
		int num;
		scanf(" %d", &num);
		
		if (num < 0) //Factorial of Negative Numbers is complex.
			printf("Not Real!\n");
			
		else if ((num == 0) || (num == 1))
			printf("1\n");
			
		else {
			long long int product = 1; //Works until 25!
			for (int i = 1; i <= num; i++)
				product *= i;
				
			result[k] = product;
		}
	}
		
	for (int k = 0; k < t; k++)
		printf("%lld\n", result[k]);
}
