#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head_node = NULL;

void rev_linked_list(int X, int Y)
{
    struct node *temp1 = head_node, *temp2 = head_node, *temp1prev = head_node, *temp2next = head_node;

    for (int i = 1; i < X - 1; i++)
        temp1prev = temp1prev->next;

    for (int i = 1; i < Y; i++)
        temp2 = temp2->next;
    temp2next = temp2->next;

    temp2->next = NULL;

    struct node *prev_node, *curr_node, *next_node;
    prev_node = NULL;

    if (temp1 != head_node)
    {
        curr_node = next_node = temp1;
        temp1prev->next = NULL;
        temp1 = temp1prev->next;
    }
    else
    {
        curr_node = next_node = head_node;
        temp1prev = NULL;
    }

    while (next_node != NULL)
    {
        next_node = next_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    struct node *swapper = temp1;
    temp1 = temp2;
    temp2 = swapper;

    if (temp1 != head_node)
        temp1prev->next = temp1;
    else
        head_node = prev_node;
    temp2->next = temp2next;
}

int node_count()
{
    struct node *temp_node = head_node;
    int count = 0;

    if (head_node == NULL)
        return count;
    else
    {
        while (temp_node != NULL)
        {
            temp_node = temp_node->next;
            count++;
        }
        return count;
    }
}

void add_node_to_end()
{
    struct node *new_node, *temp_node = head_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the value : ");
    scanf(" %d", &new_node->data);

    if (head_node == NULL)
    {
        new_node->next = head_node;
        head_node = new_node;
    }

    else
    {
        new_node->next = NULL;
        while (temp_node->next != NULL)
            temp_node = temp_node->next;

        temp_node->next = new_node;
    }
}

void display()
{
    struct node *temp_node = head_node;

    printf("\n");
    if (head_node == NULL)
        printf("The Linked List is Empty ! \n");
    else
    {
        while (temp_node != NULL)
        {
            printf("%d\n", temp_node->data);
            temp_node = temp_node->next;
        }
        printf("\n");
    }
}

void main()
{

    int choice;
    int low, high;
    while (printf("\n1. Adding a Node to the Linked List \n2. Display values of the Linked List \n3. Displaying the number of Nodes in the Linked List \n4. Reverse the Linked List \n5. Exit the Program \nPlease enter an integer choice : ") && scanf(" %d", &choice) && choice != 5)

    {
        switch (choice)
        {
        case 1:
            add_node_to_end();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Number of Nodes : %d\n", node_count());
            break;
        case 4:
            printf("Please enter X value : ");
            scanf(" %d", &low);
            printf("Please enter Y value : ");
            scanf(" %d", &high);
            rev_linked_list(low, high);
            break;
        default:
            printf("Please enter a Valid Input !\n");
        }
    }

    printf("Thanks for using !\n");
}
