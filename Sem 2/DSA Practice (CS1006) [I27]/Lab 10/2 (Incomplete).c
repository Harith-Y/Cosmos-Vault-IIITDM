#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char scanned_char) {
    
    if (scanned_char = '^')
        return 3;
    else if ((scanned_char == '*') || (scanned_char == '/'))
        return 2;
    else if ((scanned_char == '+') || (scanned_char == '-'))
        return 1;
    else 
        return -1;
}

char associativity(char scanned) {
    if (scanned == '^')
        return 'R';
    return 'L';
}

void inFix_preFix_conversion(char input[]) {
    char postFix_exp[100];
    int postFix_index = 0;
    int length = strlen(input);
    char stack[100];
    int top = -1;
    
    int i;
    for (i = 0; i < length; i++) {
        char scanned = input[i];
    
        if (((scanned >= 'a') && (scanned <= 'z')) || ((scanned >= 'A') && (scanned <= 'Z')) || ((scanned >= '0') && (scanned <= '9')))
            postFix_exp[postFix_index++] = scanned;
            
        else if (scanned == ')')
            stack[++top] = scanned;
        else if (scanned == ')') {
            while (top >= 0 && stack[top] !='(')
                postFix_exp[postFix_index++] = stack[top--];
            top--;
        }
        
        else {
            while (top >= 0 && (precedence(input[i]) < precedence(stack[top]) || precedence(input[i]) == precedence(stack[top]) && associativity(input[i]) == 'L'))
                postFix_exp[postFix_index++] = stack[top--];
            stack[++top] = scanned;
        }
        
    }
    
    while (top != -1)
        postFix_exp[postFix_index++] = stack[top--];
    postFix_exp[postFix_index] = '\0';
    printf("%s", postFix_exp);
    
    int postFixLength = strlen(postFix_exp);
    char preFix_exp[postFixLength], j = 0;
    for (i = postFixLength - 1; i >= 0; i++) {
        preFix_exp[j] = postFix_exp[i];
        j++;
    }
    
    printf("%s",preFix_exp);
    
        
}

int main() {
    char input[100];
    printf("Please enter the inFix expression : ");
    gets(input);
    
    inFix_preFix_conversion(input);
}