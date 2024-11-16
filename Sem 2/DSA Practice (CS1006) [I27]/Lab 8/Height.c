#include <stdio.h>
#include <stdlib.h>

//Defining a Tree Node
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;

//Finding the height of the Binary Tree
int height(struct node *p) {
    int h;
    if (p == NULL)
        return -1;
    int left = height(p -> left);
    int right = height(p -> right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}

//Main function
void main() {
    
    //Creating a Node
    struct node *new_node1;
    new_node1 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the value for Node 1 : ");
    scanf(" %d", &new_node1 -> data);
    new_node1 -> left = NULL;
    new_node1 -> right = NULL;
    
    //Connecting a Node to the Root
    root = new_node1;
    
    struct node *new_node2;
    new_node2 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the value for Node 2 : ");
    scanf(" %d", &new_node2 -> data);
    new_node2 -> left = NULL;
    new_node2 -> right = NULL;
    
    root -> left = new_node2;
    
    struct node *new_node3;
    new_node3 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the value for Node 3 : ");
    scanf(" %d", &new_node3 -> data);
    new_node3 -> left = NULL;
    new_node3 -> right = NULL;
    
    root -> right = new_node3;
    
    struct node *new_node4;
    new_node4 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the value for Node 4 : ");
    scanf(" %d", &new_node4 -> data);
    new_node4 -> left = NULL;
    new_node4 -> right = NULL;
    
    root-> left -> left = new_node4;
    
    struct node *new_node5;
    new_node5 = (struct node *) malloc(sizeof(struct node));
    printf("Enter the value for Node 5 : ");
    scanf(" %d", &new_node5 -> data);
    new_node5 -> left = NULL;
    new_node5 -> right = NULL;
    
    root -> left -> right = new_node5;
    
    printf("The height of the binary tree is %d", height(root));
}

