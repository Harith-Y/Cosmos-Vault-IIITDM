#include <stdio.h>

// Checking if a number is prime or not
int isPrime(int num) {
    if (num <= 1) 
    	return 0;
    	
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) 
        	return 0;
    }
    
    return 1;
}

// Power Calculator
int power(int base, int exp) {
    if (exp == 0) 
    	return 1;
    return base * power(base, exp - 1);
}

// GCD Calculator
int gcd(int a, int b) {
    if (b == 0) 
    	return a;
    return gcd(b, a % b);
}

// Driver Code
void main() {
	int t; //Testcases
	scanf(" %d", &t);
	int result[t];
	
	for (int k = 0; k < t; k++) {
		int size;
		scanf(" %d", &size);
		
		int nums[size], numsTest[size];
		int primePowers[100] = {0};
		
		for (int i = 0; i < size; i++) {
		    scanf(" %d", &nums[i]);
		    numsTest[i] = nums[i];
		}
		
		for (int i = 2; i < 100; i++) {
		    if (isPrime(i)) {
		        int minPower = -1;
		        
		        for (int j = 0; j < size; j++) {
		            int count = 0;
		            while (numsTest[k] % i == 0) {
		                numsTest[j] /= i;
		                count++; //Finding the prime factorisation of a number.
		            }
		            
		            if ((minPower == -1) || (count < minPower))
		                minPower = count;
		        }
		        primePowers[i] = minPower; //Finding the minimum power of the same prime among the numbers of the array.
		    }
		}
		
		int GCD = 1;
		for (int i = 2; i < 100; i++) {
		    if (primePowers[i] > 0)
		        GCD *= power(i, primePowers[i]);
		}
		
		result[k] = GCD;
	}
	
	for (int k = 0; k < t; k++)
		printf("%d\n", result[k]);
	
}

