#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;

//Creating a Binary Search Tree Node
struct node *create_node (int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> left = NULL)
        return create_node(value);
    
    if (value < root -> data)
        root -> left = insert_node(root -> left, value);
        
    else if (value > root -> data)
        root -> right = insert_node(root -> right, value);
    
    return root;
}

//Finding Height of a Binary Search Tree
int height(struct node *root) {
    if (root == NULL)
        return 0;
    else {
        int h;
        int left = height(root -> left);
        int right = height(root -> right);
        
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

//Executer
int main() {
    int choice, input;
    
    while (printf("1. Add Node\n2. Calculate Height\n3. Exit\nPlease enter a choice : ") && scanf(" %d", &choice) && choice != 3) {
        
        switch (choice) {
            
            case 1:
                printf("Please enter the value : ");
                scanf(" %d", &input);
                
                if (root == NULL)
                    root = insert_node(root, input);
                else
                    insert_node(root, input);
                printf("\n");
                break;
                
            case 2 :
                printf("Height of the Binary Search Tree is %d.\n\n",height(root));
                break;
            
            default :
                printf("Please enter a valid Input !\n\n");
        
        }
    
    }
    
    printf("Thanks for using !\n");
}