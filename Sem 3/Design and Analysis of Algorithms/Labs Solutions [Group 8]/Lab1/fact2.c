#include <stdio.h>

// Calculating Factorial using Recursion.
long long int factorial(int num) { 
	//Works until 25!
	if ((num == 0) || (num == 1))
		return 1;
	else
		return num * factorial(num - 1);
}

// Driver Code
void main() {
	int t; //Testcases
	scanf(" %d", &t);
	long long int result[t];
	
	for (int k = 0; k < t; k++) {
	
		int num;
		scanf(" %d", &num);
		
		if (num < 0) //Factorial of Negative Numbers is complex.
			printf("Not Real\n");
		else	
			result[k] = factorial(num);
	}
	
	for (int k = 0; k < t; k++)
		printf("%lld\n", result[k]);
}
