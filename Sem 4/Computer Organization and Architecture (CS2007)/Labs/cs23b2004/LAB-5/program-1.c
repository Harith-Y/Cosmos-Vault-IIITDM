#include <stdio.h>
#include <string.h>

void sample_function(char *input) {
    char buffer[10];
    strcpy(buffer, input);
}

void safe_function(char *input) {
    printf("In safe_function\n");
    sample_function(input);
}

int main() {
    char large_input[100];
    printf("Enter the string\n");
    scanf("%s", large_input);
    safe_function(large_input);
    printf("Main function complete.\n");
    return 0;
}

