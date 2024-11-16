#include <stdio.h>
#include <stdlib.h>
#define size 10

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push()
{
    int x;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf(" %d", &x);

    new_node->data = x;
    if (top == NULL)
    {
        new_node->next = NULL;
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

void pop()
{
    if (top == NULL)
        printf("The Stack is empty");

    else
    {
        struct node *temp;
        temp = top;
        printf("%d has been popped", temp->data);
        top = top->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void peek()
{
    printf("%d", top->data);
}

void display()
{
    if (top == NULL)
        printf("The Stack is empty");
    else
    {
        struct node *temp_node = top;
        while (temp_node != NULL)
        {
            printf("%d\n", temp_node->data);
            temp_node = temp_node->next;
        }
    }
}

void main()
{
    int choice;
    while (printf("\n1. Push an element into the Stack \n2. Pop the element from the Stack \n3. Peek the element of the Stack \n4. Displaying the elements of the Stack \n5. Exit the Program \nPlease enter an integer choice : ") && scanf(" %d", &choice) && choice != 5)

    {
        switch (choice)
        {
        case 1:
            // Push
            printf("\n");
            push();
            printf("\n");
            break;
        case 2:
            // Pop
            printf("\n");
            pop();
            printf("\n");
            break;
        case 3:
            // Peek
            printf("\n");
            peek();
            printf("\n");
            break;
        case 4:
            // Push
            printf("\n");
            display();
            printf("\n");
            break;
        default:
            printf("Invalid Input !");
        }
    }
    printf("\nThanks for using !\n\n");
}