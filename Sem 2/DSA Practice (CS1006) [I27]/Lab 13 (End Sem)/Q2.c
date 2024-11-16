#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct ListNode **head, int val)
{
    struct ListNode *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct ListNode *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse a linked list
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true; // An empty list or a list with only one node is considered a palindrome
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Finding the middle of the list
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reversing the second half of the list
    struct ListNode *secondHalf = reverseList(slow->next);

    // Comparing the first half with the reversed second half
    struct ListNode *p1 = head;
    struct ListNode *p2 = secondHalf;
    while (p2 != NULL)
    {
        if (p1->val != p2->val)
        {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

// Function to free memory allocated for the linked list
void freeList(struct ListNode *head)
{
    struct ListNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct ListNode *head = NULL;
    int n, val;

    printf("Enter the number of elements in the linked list: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input\n");
        return EXIT_FAILURE;
    }

    printf("Enter the elements of the linked list: ");
    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &val) != 1)
        {
            printf("Invalid input\n");
            freeList(head);
            return EXIT_FAILURE;
        }
        insertAtEnd(&head, val);
    }

    if (isPalindrome(head))
    {
        printf("The linked list is a palindrome.\n");
    }
    else
    {
        printf("The linked list is not a palindrome.\n");
    }

    // Free memory allocated for the linked list
    freeList(head);

    return EXIT_SUCCESS;
}
