#include <stdio.h>

// GCD Calculation of 2 numbers.
int gcdOfTwoNums(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;chat
        num2 = num1 % num2;
        num1 = temp;
    }
    
    return num1;
}

// GCD Calculator using Recursion by permuting 2 numbers at a time.
int GCD(int* inputArr, int size, int index) {
    if (index == (size - 1))
        return inputArr[index];
    
    int num1 = inputArr[index];
    int num2 = GCD(inputArr, size, index + 1);
    return gcdOfTwoNums(num1, num2);
}

// Driver Code
void main() {

	int t; //Testcases
	scanf(" %d", &t);
	int result[t];
	
	for (int k = 0; k < t; k++) {
		int size;
		scanf(" %d", &size);
		
		int nums[size];
		
		for (int i = 0; i < size; i++)
		    scanf(" %d", &nums[i]);
		   
		result[k] = GCD(nums, size, 0);
	}
	
	for (int k = 0; k < t; k++)
		printf("%d\n", result[k]);
	
}


