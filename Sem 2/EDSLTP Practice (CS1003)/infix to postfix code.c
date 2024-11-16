


//    INFIX TO POSTFIX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char data;
    struct node *next;
};
struct node *top = NULL;
int order(char c){
    if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;
}
struct node *result(struct node *head, char c){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = c;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }
    struct node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void push(char c){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = c;
    newnode->next = top;
    top = newnode;
}
char pop(){
    if(top == NULL){
        printf("no node exist\n");
        return '\0';
    }
    struct node *temp = top;
    char x = temp->data;
    top = top->next;
    free(temp);
    return x;
}
void printlist(struct node *head){
    while(head != NULL){
        printf("%c", head->data);
        head = head->next;
    }
}
void main(){
    char c[100];
    int i, a, b, l;
    struct node *head = NULL;
    char x;
    printf("Enter the expression:\n");
    scanf("%s", c);
    l = strlen(c);
    for(i = 0; i < l; i++){
        if((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= '0' && c[i] <= '9'))
            head = result(head, c[i]);
        else if(c[i] == '('){
            push(c[i]);
        }
        else if(c[i] == ')'){
            while(top->data != '('){
                x = pop();
                head = result(head, x);
            }
            pop();
        }
        else{
            a = order(c[i]);
            if(top != NULL)
                b = order(top->data);
            else
                b = -1;
            if(b < a)
                push(c[i]);
            else if(b == a){
                x = pop();
                head = result(head, x);
                push(c[i]);
            }
            else{
                while(b >= a){
                    x = pop();
                    head = result(head, x);
                    if(top != NULL)
                        b = order(top->data);
                    else
                        b = -1;
                }
                push(c[i]);
            }
        }
    }
    while(top != NULL){
        x = pop();
        head = result(head, x);
    }
    printlist(head);
    while(head != NULL){
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
