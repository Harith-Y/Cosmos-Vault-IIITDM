#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue()
{
    int x;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf(" %d", &x);
    new_node->data = x;
    new_node->next = NULL;
    if (front == NULL)
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue()
{
    if (front == NULL)
        printf("The Queue is empty");

    else if (front->next = NULL)
    {
        printf("%d", front->data);
        front = rear = NULL;
    }

    else
    {
        struct node *temp;
        temp = front;
        printf("%d has been popped", front->data);
        front = temp->next;
        temp->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void peek()
{
    printf("%d", front->data);
}

void display()
{
    if (front == NULL)
        printf("The Queue is empty");
    else
    {
        struct node *temp_node = front;
        while (temp_node != rear)
        {
            printf("%d\n", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("%d\n", temp_node->data);
    }
}

void main()
{
    int choice;
    while (printf("\n1. Enqueue an element into the Queue \n2. Dequeue the element from the Queue \n3. Peeking the element of the Queue \n4. Displaying the elements of the Queue \n5. Exit the Program \nPlease enter an integer choice : ") && scanf(" %d", &choice) && choice != 5)

    {
        switch (choice)
        {
        case 1:
            // Enqueue
            printf("\n");
            enqueue();
            printf("\n");
            break;
        case 2:
            // Dequeue
            printf("\n");
            dequeue();
            printf("\n");
            break;
        case 3:
            // Peek
            printf("\n");
            peek();
            printf("\n");
            break;
        case 4:
            // Display
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