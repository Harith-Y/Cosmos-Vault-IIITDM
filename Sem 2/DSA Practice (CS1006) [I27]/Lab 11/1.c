#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;

//Creating a Binary Search Tree Node
struct node *create_node(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node -> left = NULL;
    new_node -> data = value;
    new_node -> right = NULL;
    return new_node;
}

//Searching for a user-given key in a Binary Search Tree
struct node *search_node(struct node *root, int key) {
    if ((root == NULL) || (root -> data == key))
        return root;

    if (root -> data < key)
        return search_node(root -> right, key);
        
    return search_node(root -> left, key);
    
}

//Inserting a node into a Binary Search Tree
struct node *insert_node(struct node *root, int value) {
    if (root == NULL)
        return create_node(value);
        
    if (value < root -> data)
        root -> left = insert_node(root -> left, value);
        
    else if (value > root -> data)
        root -> right = insert_node(root -> right, value);
        
    return root;
}


//Executer
void main() {
    
    int choice, input;
    while(printf("1. Add Node\n2. Search Node\n3. Exit\nPlease enter a choice : ") && scanf(" %d", &choice) && (choice != 3)) {
        
        switch (choice) {
            
            case 1 : 
                printf("Please Enter the value : ");
                scanf(" %d", &input);
                
                if (root == NULL) 
                    root = insert_node(root, input);
                else
                    insert_node(root, input);
                printf("\n");
                break;
        
            case 2 :
                printf("Please Enter the value : ");
                scanf(" %d", &input);
                if (search_node(root, input) != NULL)
                    printf("Congo ! Element %d found.\n", input);
                else 
                    printf("Alas ! Element %d not found.\n", input);
                printf("\n");
                break;
                    
            default :
                printf("Please enter a valid Input !\n\n");
            
        }
    }
    
    printf("Thanks for using !\n");
    
}