#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;

//Creating a Binary Search Tree Node
struct node *create_node(int value) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> left = NULL;
    new_node -> data = value;
    new_node -> right = NULL;
    
    return new_node;
}

//Inserting a node in a Binary Search Tree
struct node *insert_node(struct node *root, int value) {
    if (root == NULL)
        return create_node(value);
    
    if (value < root -> data)
        root -> left = insert_node(root -> left, value);
        
    else if (value > root -> data)
        root -> right = insert_node(root -> right, value);
        
    return root;
}

//Displaying Elements
void inOrder(struct node *root){
    if (root != NULL) {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

//Finding a User-given key in the Binary Search Tree.
struct node *search_node(struct node *root, int key) {
    if ((root == NULL) || (root -> data = key))
        return root;
    
    if (root -> data < key)
        return search_node(root -> right, key);
    return search_node(root -> left, key);
}

//Finding the Smallest element from the Right Subtree for deletion.
struct node *smallest_from_right(struct node *root) {
    if (root == NULL)
        return NULL;
        
    else if (root -> left != NULL)
        return smallest_from_right(root -> left);
        
    return root;
}

//Finding the Largest element from the Left Subtree for deletion.
struct node *largest_from_left(struct node *root) {
    if (root == NULL)
        return NULL;
    
    else if (root -> right != NULL)
        return largest_from_left(root -> right);
    
    return root;
}

//Deleting a node from a Binary Search Tree
struct node *delete_node(struct node *root, int value) {
    
    // if (search_node(root, value) != NULL)
    //     printf("Node deleted.\n");
            
    // else
    //     printf("No Node exists with data %d", value);
        
        
    if (root == NULL)
        return root;
    if (value > root -> data)
        root -> right = delete_node(root -> right, value);
    
    else if (value < root -> data)
        root -> left = delete_node(root -> left, value);
    
    else {
        if ((root -> left == NULL) && (root -> right == NULL)) {
            free(root);
            return NULL;
        }
    
        else if ((root -> left == NULL) || (root -> right == NULL)) {
            struct node *temp_node;
            if (root -> left = NULL)
                temp_node = root -> right;
            
            else
                temp_node = root -> left;
            
            free(root);
            return temp_node;
        }
        
        else {
            char choice;
            printf("Delete from left (L) or right (R) ? : ");
            scanf(" %c", &choice);
            
            if (choice == 'R' || choice == 'r') {
                struct node *temp_node = smallest_from_right(root -> left);
                root -> data = temp_node -> data;
                root -> left = delete_node(root -> left, temp_node -> data);
            }
            else if (choice == 'L' || choice == 'l') {
                struct node *temp_node = largest_from_left(root -> right);
                root -> data = temp_node -> data;
                root -> right = delete_node(root -> right, temp_node -> data);
            }
            else
                printf("Please enter a valid input ! Element not deleted.\n");
            
        }
    
    }
    
    return root;
}

//Executer
void main() {
    int choice, input;
    
    while (printf("1. Add Node\n2. Delete Node\n3. Display\n4. Exit\nPlease enter a choice : ") && scanf(" %d", &choice) && (choice != 4)) {
        
        switch (choice) {
            
            case 1 :
                printf("Please enter the value : ");
                scanf(" %d", &input);
                
                if (root == NULL)
                    root = insert_node(root, input);
                else
                    insert_node(root, input);
                printf("\n");
                break;
                
            case 2 :
                printf("Please enter the value to be deleted : ");
                scanf(" %d", &input);
                delete_node(root, input);
                printf("\n");
                break;
            
            case 3 :
                inOrder(root);
                printf("\n\n");
                break;
            
            default :
                printf("Please enter a valid Input !\n\n");
        }
        
    }
    
    printf("Thanks for using !\n");
}