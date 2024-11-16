#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure for level order traversal
struct Queue
{
    int front, rear;
    int capacity;
    struct TreeNode **array;
};

// Function to create a new queue
struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (struct TreeNode **)malloc(queue->capacity * sizeof(struct TreeNode *));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to enqueue a node into the queue
void enqueue(struct Queue *queue, struct TreeNode *item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    if (queue->front == -1)
        queue->front = queue->rear;
}

// Function to dequeue a node from the queue
struct TreeNode *dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;
    struct TreeNode *item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % queue->capacity;
    return item;
}

// Function to create a new binary tree node
struct TreeNode *newNode(int data)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to build a binary tree from level order input
struct TreeNode *buildTreeLevelOrder()
{
    int data;
    printf("Enter the root value: ");
    if (scanf("%d", &data) != 1)
    {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }
    struct TreeNode *root = newNode(data);
    struct Queue *queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue))
    {
        struct TreeNode *current = dequeue(queue);
        printf("Enter left child value of %d (or -1 for no node): ", current->data);
        if (scanf("%d", &data) != 1)
        {
            printf("Invalid input\n");
            exit(EXIT_FAILURE);
        }
        if (data != -1)
        {
            current->left = newNode(data);
            enqueue(queue, current->left);
        }
        printf("Enter right child value of %d (or -1 for no node): ", current->data);
        if (scanf("%d", &data) != 1)
        {
            printf("Invalid input\n");
            exit(EXIT_FAILURE);
        }
        if (data != -1)
        {
            current->right = newNode(data);
            enqueue(queue, current->right);
        }
    }

    return root;
}

// Function to mirror a binary tree
void mirrorTree(struct TreeNode *node)
{
    if (node == NULL)
        return;

    // Swap left and right child nodes
    struct TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;

    // Recursively mirror left and right subtrees
    mirrorTree(node->left);
    mirrorTree(node->right);
}

// Function to print the inorder traversal of a binary tree
void inorderTraversal(struct TreeNode *node)
{
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

int main()
{
    struct TreeNode *root = buildTreeLevelOrder();

    printf("Inorder traversal of the original binary tree: ");
    inorderTraversal(root);

    // Mirror the binary tree
    mirrorTree(root);

    printf("\nInorder traversal of the mirrored binary tree: ");
    inorderTraversal(root);

    return 0;
}