#include <stdio.h>
int main() {
    int num, i, prime;
 
    for (num = 2; num <= 100; num++) {
        prime = 1;
 
        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                prime = 0;
                break;
            }
        }
 
        if (prime == 1) {
            printf("%d is a prime number\n", num);
        }
    }
 
    return 0;
}

