#include <stdio.h>
void reverse_string(char *str) {
    int start = 0;
    int end = 0;
    while (str[end] != '\0') {
        end++;
    }
 
    while (start < end) {
        char temp = str[start];
        str[start] = str[end - 1];
        str[end - 1] = temp;
        start++;
        end--;
    }
}
 
int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
 
    return 0;
}
