#include <stdio.h>
#include <stdlib.h>
#define size 10
int queue[size];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    if (rear == size - 1)
        printf("The Queue is Full \n");

    else if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        queue[rear] = x;
    }

    else
    {
        printf("Enter the value : ");
        scanf(" %d", &x);
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if ((front == -1) && (rear == -1))
        printf("The Queue is empty");

    else if (front == rear)
    {
        printf("%d", queue[front]);
        front = rear = -1;
    }

    else
    {
        printf("%d has been popped", queue[front]);
        front = front + 1;
    }
}

void peek()
{
    if ((front == -1) && (rear == -1))
        printf("The Queue is Empty");
    else
        printf("%d", queue[front]);
}

void display()
{
    if ((front == -1) && (rear == -1))
        printf("The Queue is Empty");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d\n", queue[i]);
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