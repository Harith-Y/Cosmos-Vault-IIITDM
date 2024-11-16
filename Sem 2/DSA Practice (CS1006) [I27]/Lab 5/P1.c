#include <stdio.h>
#include <stdlib.h>
#define size 10
int stack[size];
int top = -1;

void push()
{
	int x;
	if (top == size - 1)
		printf("The stack is Full \n");

	else
	{
		printf("Enter the value : ");
		scanf(" %d", &x);
		top = top + 1;
		stack[top] = x;
	}
}

void pop()
{
	if (top == -1)
		printf("The Stack is empty");

	else
	{
		printf("%d has been popped", stack[top]);
		top = top - 1;
	}
}

void peek()
{
	if (top == -1)
		printf("The Stack is empty");
	else
		printf("%d", stack[top]);
}

void display()
{
	if (top == -1)
		printf("The Stack is empty");
	else
	{
		for (int i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
}

void main()
{
	int choice;
	while (printf("\n1. Push an element into the Stack \n2. Pop the element from the Stack \n3. Peek the element of Stack \n4. Displaying the elements of the Stack \n5. Exit the Program \nPlease enter an integer choice : ") && scanf(" %d", &choice) && choice != 5)

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