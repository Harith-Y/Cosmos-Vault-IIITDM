#include <stdio.h>

int main() {
    int i;
    int num = 10;
    int denom;
 
    for (i = 0; i < 5; i++) {
        denom = i - 1;  // This will be 0 when i = 1
        printf("Dividing %d by %d\n", num, denom);
        int result = num / denom; 
        printf("Result: %d\n", result);
    }
    return 0;
}
