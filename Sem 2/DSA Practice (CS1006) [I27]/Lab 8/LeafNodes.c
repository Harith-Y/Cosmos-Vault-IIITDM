#include <stdio.h>
#include <stdlib.h>

//Defining a Tree Node
struct node {
    struct node *left;
    int data;
    struct node *right;
}; 
struct node *root = NULL;

//Counting all Nodes
int count_nodes(struct node *root) {
    if (root == NULL)
        return 0;
    return (1 + count_nodes(root -> left) + count_nodes(root -> right));
}

//Counting all Nodes except all the Leaf Nodes
int count_prev_nodes(struct node *root) {
    if ((root -> right == NULL) && (root -> left == NULL))
        return 0;
    return (1 + count_prev_nodes(root -> left) + count_prev_nodes(root -> right));
}


void main() {
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    printf("Enter the Value for Node 1: ");
    scanf(" %d", &new_node -> data);
    new_node -> left = NULL;
    new_node -> right =NULL;
    
    root = new_node;
    
    struct node *new_node2;
    new_node2 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the Value for Node 2: ");
    scanf(" %d", &new_node2 -> data);
    new_node2 -> left = NULL;
    new_node2 -> right =NULL;
    
    root -> left = new_node2;
    
    struct node *new_node3;
    new_node3 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the Value for Node 3: ");
    scanf(" %d", &new_node3 -> data);
    new_node3 -> left = NULL;
    new_node3 -> right =NULL;
    
    root -> right = new_node3;
    
    struct node *new_node4;
    new_node4 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the Value for Node 4: ");
    scanf(" %d", &new_node4 -> data);
    new_node4 -> left = NULL;
    new_node4 -> right =NULL;
    
    root -> left -> left = new_node4;
    
    struct node *new_node5;
    new_node5 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the Value for Node 5: ");
    scanf(" %d", &new_node5 -> data);
    new_node5 -> left = NULL;
    new_node5 -> right =NULL;
    
    root -> left -> right = new_node5;
    
    printf("The number of leaf nodes : %d.", count_nodes(root) - count_prev_nodes(root));
}