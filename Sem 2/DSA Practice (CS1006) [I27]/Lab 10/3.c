#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *create_node(int value) {
    struct node *new_node = (struct node *)malloc (sizeof(struct node));
    new_node -> data = value;
    new_node -> left = new_node -> right = NULL;

    return new_node;
}

struct node *insert_node(struct node *root, int input) {
   
    if (root == NULL)
        return create_node(input);
    else if (input < root -> data)
        root -> left = insert_node(root -> left, input);
    else if (input > root -> data)
        root -> right = insert_node(root -> right, input);
    return root;
}

void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

int main() {
    
    root = insert_node(root, 10);
    
    int node_count, input_data, i=1;
    
    printf("Please enter the total number of Nodes in the Binary Search Tree : ");
    scanf(" %d", &node_count);
    
    while (i-1 < node_count) {
        printf("Enter the Value in Node %d : ", i);
        scanf(" %d", &input_data);
        insert_node(root, input_data);
        i++;
    }
    
    
    printf("The elements in inOrder Traversal : \n");
    inOrder(root);
    printf("\n");
}