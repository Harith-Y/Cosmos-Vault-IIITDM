#include<stdio.h>
#include<stdlib.h>

//Defining a Structure Node
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head_node = NULL;
struct node *tail_node = NULL;

//Counting the number of nodes of a Circular Doubly Linked List
int count_nodes() {
    struct node *temp_node = head_node;
    int count = 0;
    
    if (head_node == NULL)
        return count;
    else {
        do {
            temp_node = temp_node -> next;
            count++;
        }
        while (temp_node != head_node);
        return count;
    }
}

//Inserting a Node at the beginning of a Circular Doubly Linked List.
void insert_at_begin() {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value : ");
    scanf(" %d", &new_node -> data);
    new_node -> prev = NULL;
    new_node -> next = NULL;
    
    if (head_node == NULL) {
        head_node = tail_node = new_node;
        tail_node -> next = new_node;
        tail_node -> prev = new_node;
    }
    
    else {
        new_node -> next = head_node;
        head_node = new_node;
        tail_node -> next = head_node;
        head_node -> prev = tail_node;
    }
}

//Inserting a Node at the ending of a Circular Doubly Linked List.
void insert_at_end() {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value : ");
    scanf(" %d", &new_node -> data);
    new_node -> prev = NULL;
    new_node -> next = NULL;
    
    if (head_node == NULL) {
        head_node = tail_node = new_node;
        tail_node -> next = new_node;
        tail_node -> prev = new_node;
    }
    
    else {
        new_node -> prev = tail_node;
        tail_node -> next = new_node;
        tail_node = tail_node-> next;
        head_node -> prev = tail_node;
        tail_node -> next = head_node;
    }
}

//Inserting a Node at a particular position of a Circular Doubly Linked List.
void insert_at_pos() {
    int pos, i = 1;
    printf("Enter the Position at which you want to insert the node : ");
    scanf(" %d", &pos);
    int node_count = count_nodes();
    
    if (pos > node_count + 1)
        printf("\nPlease enter a Valid Position ! \n");
        
    else if (pos == 1)
        insert_at_begin();
    else if (pos == node_count + 1)
        insert_at_end();
    else {
        struct node *new_node, *temp_node = head_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> prev = NULL;
        new_node -> next = NULL;
        
        while (i < pos - 1) {
            temp_node = temp_node -> next;
            i++;
        }
    
        new_node -> next = temp_node -> next;
        new_node -> prev = temp_node;
        temp_node -> next -> prev = new_node;
        temp_node -> next = new_node;
    }
}

//Inserting a Node after a particular node corresponding to a user-given data element of a Circular Doubly Linked List.
void insert_after_node() {
    int count = 1, Flag = 1, search_data;
    struct node *new_node, *temp_node = head_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value after which you want the new Node to be added : ");
    scanf(" %d", &search_data);
    new_node -> prev = NULL;
    new_node -> next = NULL;
    
    if (head_node -> data == search_data) {
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> prev = NULL;
        new_node -> next = NULL;
        
        new_node -> next = temp_node -> next;
        new_node -> prev = temp_node;
        temp_node -> next -> prev = new_node;
        temp_node -> next = new_node;
    }
    
    else if (tail_node -> data == search_data)
        insert_at_end();
    
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data == search_data) {
                Flag = 0;
                break;
            }
        }
        
        while (temp_node -> data != search_data);
        
        if (Flag == 1)
            printf("\nData does not exist in the Linked List !\n");
        else {
            printf("Enter the Value : ");
            scanf(" %d", &new_node -> data);
            new_node -> prev = NULL;
            new_node -> next = NULL;
            
            new_node -> next = temp_node -> next;
            new_node -> prev = temp_node;
            temp_node -> next -> prev = new_node;
            temp_node -> next = new_node;
        }
    }
}

//Inserting a Node before a particular node corresponding to a user-given data element of a Circular Doubly Linked List.
void insert_before_node() {
    int count = 1, Flag = 1, i = 1, j = 1, search_data;
    struct node *new_node, *temp_node = head_node, *temp_temp_node = head_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value before which you want the new Node to be added : ");
    scanf(" %d", &search_data);
    new_node -> prev = NULL;
    new_node -> next = NULL;
    
    int node_count = count_nodes();
    
    if (head_node -> data == search_data)
        insert_at_begin();
    
    else if (tail_node -> data == search_data) {
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> prev = NULL;
        new_node -> next = NULL;
        
        while (i < node_count - 1) {
            temp_node = temp_node -> next;
            i++;
        }
        
        new_node -> next = temp_node -> next;
        new_node -> prev = temp_node;
        temp_node -> next -> prev = new_node;
        temp_node -> next = new_node;
    }
    
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data = search_data) {
                Flag = 0;
                break;
            }
        }
        
        while (temp_node -> data != search_data);
        
        if (Flag == 1)
            printf("\nData does not exist in the Linked List !\n");
        else {
            printf("Enter the Value : ");
            scanf(" %d", &new_node -> data);
            new_node -> prev = NULL;
            new_node -> next = NULL;
            
            while (j < count - 1) {
                temp_temp_node = temp_temp_node -> next;
                j++;
            }
            
            new_node -> next = temp_temp_node -> next;
            new_node -> prev = temp_temp_node;
            temp_temp_node -> next -> prev = new_node;
            temp_temp_node -> next = new_node;
        }
    }
}

//Deleting a Node at the beginning of a Circular Doubly Linked List.
void delete_at_begin() {
    if (head_node == NULL)
        printf("\nThe Linked List is Empty !\n");
        
    else if (head_node -> next == NULL) {
        free(head_node);
        head_node = tail_node = NULL;
    }
    
    else {
        struct node *temp_node = head_node;
        head_node = temp_node -> next;
        tail_node -> next = head_node;
        head_node -> prev = tail_node;
        
        temp_node -> next = temp_node -> prev = NULL;
        free(temp_node);
        temp_node = NULL;
        
        printf("\nNode Deleted !\n");
    }
}

//Deleting a Node at the ending of a Circular Doubly Linked List.
void delete_at_end() {
    if (head_node == NULL)
        printf("\nThe Linked List is Empty !\n");
        
    else if (head_node -> next == head_node) {
        free(head_node);
        head_node = tail_node = NULL;
    }
    
    else {
        struct node *temp_node = tail_node;
        tail_node = tail_node -> prev;
        tail_node -> next = head_node;
        head_node -> prev = tail_node;
        
        temp_node -> next = temp_node -> prev = NULL;
        free(temp_node);
        temp_node = NULL;
        
        printf("\nNode Deleted !\n");
    }
}

//Deleting a Node at a particular position of a Circular Doubly Linked List.
void delete_at_pos() {
    int pos, i = 1;
    printf("Enter the position at which you want to delete the node : ");
    scanf(" %d", &pos);
    
    int node_count = count_nodes();
    
    if (head_node == NULL)
        printf("\nThe Linked List is Empty !\n");
        
    else if (pos > node_count)
        printf("\nPlease enter a Valid Position ! \n");
        
    else if (pos == node_count)
        delete_at_end();
    else if (pos == 1)
        delete_at_begin();
    else {
        struct node *temp_node = head_node;
        
        while (i < pos) {
            temp_node = temp_node -> next;
            i++;
        }
        
        temp_node -> prev -> next = temp_node -> next;
        temp_node -> next -> prev = temp_node -> prev;
        
        temp_node -> prev = temp_node -> next = NULL;
        free(temp_node);
        temp_node = NULL;
        
        printf("\nNode Deleted !\n");
    }
}

//Deleting a Node after a particular node corresponding to a user-given data element of a Circular Doubly Linked List.
void delete_after_node() {
    int count = 1, Flag = 1, search_data;
    struct node *temp_node = head_node;
    printf("Enter the Value after which you want the Node to be deleted : ");
    scanf(" %d", &search_data);
    
    if (head_node == NULL)
        printf("\nThe Linked List is Empty !\n");
        
    else if (head_node -> data == search_data) {
        temp_node -> prev -> next = temp_node -> next;
        temp_node -> next -> prev = temp_node -> prev;
        
        temp_node -> prev = temp_node -> next = NULL;
        free(temp_node);
        temp_node = NULL;
        
        printf("\nNode Deleted !\n");
    }
    
    else if (tail_node -> data == search_data)
        printf("\nNo Node exists !\n");
    
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data == search_data) {
                Flag = 0;
                break;
            }
        }
        
        while (temp_node -> data != search_data);
        
        if (Flag == 1)
            printf("\nData does not exist in the Linked List !\n");
        else {
            temp_node = temp_node -> next;
            temp_node -> prev -> next = temp_node -> next;
            temp_node -> next -> prev = temp_node -> prev;
            
            temp_node -> prev = temp_node -> next = NULL;
            free(temp_node);
            temp_node = NULL;
            
            printf("\nNode Deleted !\n");
        }
    }
}

//Deleting a Node before a particular node corresponding to a user-given data element of a Circular Doubly Linked List.
void delete_before_node() {
    int count = 1, Flag = 1, i = 1, j = 1, search_data;
    struct node *temp_node = head_node, *temp_temp_node = head_node;
    printf("Enter the Value before which you want the Node to be deleted : ");
    scanf(" %d", &search_data);
    
    int node_count = count_nodes();
        
    if (head_node == NULL)
        printf("\nThe Linked List is Empty !\n");
        
    else if (head_node -> data == search_data)
        printf("\nNo Node Exists !\n");
    
    else if (tail_node -> data == search_data) {
        while (i < node_count - 1) {
            temp_node = temp_node -> next;
            i++;
        }
        
        temp_node -> prev -> next = temp_node -> next;
        temp_node -> next -> prev = temp_node -> prev;
        
        temp_node -> prev = temp_node -> next = NULL;
        free(temp_node);
        temp_node = NULL;
        
        printf("\nNode Deleted !\n");
    }
    
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data = search_data) {
                Flag = 0;
                break;
            }
        }
        
        while (temp_node -> data != search_data);
        
        if (Flag == 1)
            printf("\nData does not exist in the Linked List !\n");
        else {
            while (j < count - 1) {
                temp_temp_node = temp_temp_node -> next;
                j++;
            }
            
            temp_temp_node -> prev -> next = temp_temp_node -> next;
            temp_temp_node -> next -> prev = temp_temp_node -> prev;
            
            temp_temp_node -> prev = temp_temp_node -> next = NULL;
            free(temp_temp_node);
            temp_temp_node = NULL;
            
            printf("\nNode Deleted !\n");
        }
    }
}

//Displaying all the elements in the forward order of a Circular Doubly Linked List.
void display() {
    
    struct node *temp_node = head_node;
    
    if (head_node == NULL)
        printf("\nThe Linked List is Empty ! \n");
        
    else {
         do {
            printf("%d\n", temp_node -> data);
            temp_node = temp_node -> next;
        }
        while (temp_node != head_node);
        printf("\n");
    }
}

//Displaying all the elements in the reverse order of a Circular Doubly Linked List.
void rev_display() {
    struct node *temp_node = tail_node;
    
    if (head_node == NULL)
        printf("\nThe Linked List is Empty ! \n");
        
    else {
        do {
            printf("%d\n", temp_node -> data);
            temp_node = temp_node -> prev;
        }
        while (temp_node != tail_node);
        printf("\n");
    }
}

//Main Function
void main() {
    int choice;
    while (printf("1. Insert a Node at the beginning of the Linked List\n2. Insert a Node at the end of the Linked List\n3. Insert a Node at a particular position of the Linked List\n4. Insert a Node after a particular node of the Linked List\n5. Insert a Node before a particular node of the Linked List\n6. Delete a Node at the beginning of the Linked List\n7. Delete a Node at the end of the Linked List\n8. Delete a Node at a particular position of the Linked List\n9. Delete a Node after a particular node of the Linked List\n10. Delete a Node before a particular node of the Linked List\n11. Display all the elements of the Linked List\n12. Display all the elements in the reverse order of the Linked List\n13. Quit\nPlease Enter a Integer Choice : ") && scanf(" %d", &choice) && choice != 13) {
        switch(choice) {
            
            case 1:
                //Inserting a Node at the beginning of the Circular Doubly Linked List.
                printf("\n");
                insert_at_begin();
                printf("\n");
                break;
                
            case 2:
                //Inserting a Node at the end of the Circular Doubly Linked List.
                printf("\n");
                insert_at_end();
                printf("\n");
                break;
                
            case 3:
                //Inserting a Node at a particular position of the Circular Doubly Linked List.
                printf("\n");
                insert_at_pos();
                printf("\n");
                break;
                
            case 4:
                //Inserting a Node after a particular node of the Circular Doubly Linked List.
                printf("\n");
                insert_after_node();
                printf("\n");
                break;
                
            case 5:
                //Inserting a Node before a particular node of the Circular Doubly Linked List.
                printf("\n");
                insert_before_node();
                printf("\n");
                break;
                
            case 6:
                //Deleting a Node at the beginning of the Circular Doubly Linked List.
                delete_at_begin();
                printf("\n");
                break;
                
            case 7:
                //Deleting a Node at the end of the Circular Doubly Linked List.
                delete_at_end();
                printf("\n");
                break;
                
            case 8:
                //Deleting a Node at a particular position of the Circular Doubly Linked List.
                delete_at_pos();
                printf("\n");
                break;
                
            case 9:
                //Deleting a Node after a particular node of the Circular Doubly Linked List.
                delete_after_node();
                printf("\n");
                break;
                
            case 10:
                //Deleting a Node before a particular node of the Circular Doubly Linked List.
                delete_before_node();
                printf("\n");
                break;
                
            case 11:
                //Displaying all the elements of the Cicular Doubly Linked List.
                printf("\n");
                display();
                printf("\n");
                break;
                
            case 12:
                //Displaying all the elements in the reverse order of the Cicular Doubly Linked List.
                printf("\n");
                rev_display();
                printf("\n");
                break;
                
            default:
                printf("Please Enter a Valid Input !");
        }
        
    }
    
    printf("Thanks for Using !\n\n");
}