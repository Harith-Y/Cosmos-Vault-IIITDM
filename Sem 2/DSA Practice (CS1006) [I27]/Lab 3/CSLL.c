#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head_node = NULL;
struct node *tail_node = NULL;



// void create_node()
// {
//     struct node *new_node;
//     new_node = (struct node *)malloc(sizeof(struct node));
//     printf("Enter the Value : ");
//     scanf(" %d", &new_node -> data);
//     new_node -> next = NULL;
    
//     if (head_node == NULL) {
//         head_node = tail_node = new_node;
//         tail_node -> next = head_node;
//     }
    
//     else {
//         tail_node -> next = new_node;
//         tail_node = new_node;
//         tail_node -> next = head_node;
//     }
// }



//Inserting a Node at the beginning of a Circular Singly Linked List
void insert_at_begin()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value : ");
    scanf(" %d", &new_node -> data);
    new_node -> next = NULL;
    
    if (head_node == NULL){
        head_node = tail_node = new_node;
        tail_node -> next = new_node;
    }
    
    else {
        new_node -> next = head_node;
        head_node = new_node;
        tail_node -> next = head_node;
    }
    
}

//Inserting a Node at the end of a Circular Singly Linked List
void insert_at_end()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value : ");
    scanf(" %d", &new_node -> data);
    new_node -> next = NULL;
    
    if (head_node == NULL){
        head_node = tail_node = new_node;
        tail_node -> next = new_node;
    }
    
    else {
        tail_node -> next = new_node;
        tail_node = new_node;
        tail_node -> next = head_node;
    }
    
}

//Counting the number of nodes of a Circular Singly Linked List
int nodes_count() {
    int count = 0;
    struct node *temp_node = head_node;
    
    if (head_node == NULL)
        return count;
    
    else {
        
        do {
            temp_node = temp_node -> next;
            count++;
        }
        while (temp_node != head_node);
        printf("\n");
        
        return count;
    }
}

//Displaying all the elements in the Circular Singly Linked List
void display() {
    struct node *temp_node = head_node;
    
    if (head_node == NULL)
        printf("The Linked List is Empty !\n");
    
    else {
        
        do {
            printf("%d\n", temp_node -> data);
            temp_node = temp_node -> next;
        }
        while (temp_node != head_node);
        printf("\n");
    }
}

//Inserting a Node at a particular position in a Circular Singly Linked List
void insert_at_pos() {
    int i=1, pos;
    printf("Enter the Position at which you want the node to be inserted : ");
    scanf(" %d", &pos);
    
    int node_count = nodes_count();
    if (pos > node_count)
        printf("Invalid Position !\n");
        
    else if (pos == node_count)
        insert_at_end();
        
    else {
        struct node *new_node, *temp_node = head_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> next = NULL;
        
        while (i < pos - 1) {
            temp_node = temp_node -> next;
            i++;
        }
        
        new_node -> next = temp_node -> next;
        temp_node -> next = new_node;
        
    }

}

//Inserting a Node after a node corresponding to a particular User-Given Data element 
void insert_after_node() {
    int count = 1, Flag = 1, search_data;
    struct node *new_node;
    struct node *temp_node = head_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value after which you want the New Node to be added : ");
    scanf(" %d",&search_data);
    
    if (head_node -> data == search_data) {
    
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> next = NULL;
        
        new_node -> next = temp_node -> next;
        temp_node -> next = new_node;
        
    }
    else if (tail_node -> data == search_data) {
    
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> next = NULL;
        
        temp_node = tail_node;
        new_node -> next = temp_node -> next;
        temp_node -> next = new_node;
        
    }
        
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data == search_data){
                Flag = 0;
                break;
            }
        }
        while ((temp_node -> data != search_data));
        
        if (Flag == 1)
            printf("Data does not exist in the Linked List");
        else {
            printf("Enter the Value : ");
            scanf(" %d", &new_node -> data);
            new_node -> next = NULL;
            
            new_node -> next = temp_node -> next;
            temp_node -> next = new_node;
        }
    }
    
}

//Inserting a Node before a node corresponding to a particular User-Given Data element 
void insert_before_node() {
    int count = 1, i = 1, j = 1, Flag = 1, search_data;
    struct node *new_node;
    struct node *temp_node = head_node;
    struct node *tempp_node = head_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Value before which you want the New Node to be added : ");
    scanf(" %d",&search_data);
    
    int node_count = nodes_count();
    
    if (head_node -> data == search_data) {
        insert_at_begin();
    }
    else if (tail_node -> data == search_data) {
    
        printf("Enter the Value : ");
        scanf(" %d", &new_node -> data);
        new_node -> next = NULL;
        
        while (i < node_count - 1) {
            temp_node = temp_node -> next;
            i++;
        }
        
        new_node -> next = temp_node -> next;
        temp_node -> next = new_node;
        
    }
        
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data == search_data){
                Flag = 0;
                break;
            }
        }
        while ((temp_node -> data != search_data));
        
        if (Flag == 1)
            printf("Data does not exist in the Linked List");
        else {
            printf("Enter the Value : ");
            scanf(" %d", &new_node -> data);
            new_node -> next = NULL;
            
            while (j < count - 1) {
                tempp_node = tempp_node -> next;
                j++;
            }
            
            new_node -> next = tempp_node -> next;
            tempp_node -> next = new_node;
        }
    }
}

//Deleting a Node at the beginning of the Ciruclar Singly Linked List
void delete_at_begin() {
    if (head_node == NULL)
        printf("The Linked List is Empty !\n");
    else if (head_node -> next == head_node) {
        free(head_node);
        head_node = NULL;
    }
    else {
        struct node *temp_node = head_node;
        while (temp_node -> next != head_node) {
            temp_node = temp_node -> next;
        }
        
        temp_node -> next = head_node -> next;
        free(head_node);
        head_node = temp_node -> next;
    }
    
}

//Deleting a Node at the end of the Circular Singly Linked List
void delete_at_end() {
    if (head_node == NULL)
        printf("The Linked List is Empty !\n");
    else if (head_node -> next == head_node) {
        free(head_node);
        head_node = NULL;
    }
    else {
        struct node *prev_node = NULL;
        struct node *temp_node = head_node;
        while (temp_node -> next != head_node) {
            prev_node = temp_node;
            temp_node = temp_node -> next;
        }

        prev_node -> next = temp_node -> next;
        free(temp_node);
        temp_node = NULL;
        
    }        
}

//Deleting a Node at a particular position in a Circular Singly Linked List
void delete_at_pos() {
    int i = 1, pos;
    printf("Enter the Position at which you want the node to be deleted : ");
    scanf(" %d", &pos);
    
    int node_count = nodes_count();
    if (pos > node_count)
        printf("Invalid Position !\n");
        
    else if (pos == node_count)
        delete_at_end();
        
    else if (pos == 1)
        delete_at_begin();
        
    else {
        struct node *temp_node = head_node, *prev_node;
        
        while (i < pos - 1) {
            temp_node = temp_node -> next;
            i++;
        }
        
        prev_node = temp_node -> next;
        temp_node -> next = prev_node -> next;
        prev_node -> next = NULL;
        
        free(prev_node);
        prev_node = NULL;
        
    }
    
}

//Deleting a Node after a node corresponding to a particular User-Given Data element 
void delete_after_node() {
    int count = 1, i = 1, Flag = 1, search_data;
    struct node *temp_node = head_node, *prev_node;
    printf("Enter the Value after which you want the Node to be deleted : ");
    scanf(" %d",&search_data);
    
    if (head_node -> data == search_data) {
        prev_node = temp_node -> next;
        temp_node -> next = prev_node -> next;
        prev_node -> next = NULL;
        
        free(prev_node);
        prev_node = NULL;
    }
    else if (tail_node -> data == search_data) {
        printf("No Node exists !\n");
    }
        
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data == search_data){
                Flag = 0;
                break;
            }
        }
        while ((temp_node -> data != search_data));
        
        if (Flag == 1)
            printf("Data does not exist in the Linked List");
        else {
            prev_node = temp_node -> next;
            temp_node -> next = prev_node -> next;
            prev_node -> next = NULL;
            
            free(prev_node);
            prev_node = NULL;
        }
    }
    
}

//Deleting a Node before a node corresponding to a particular User-Given Data element 
void delete_before_node() {
    int count = 1, i = 1, j = 1, Flag = 1, search_data;
    struct node *temp_node = head_node, *prev_node;
    struct node *tempp_node = head_node;
    printf("Enter the Value before which you want the Node to be deleted : ");
    scanf(" %d",&search_data);
    
    int node_count = nodes_count();
    
    if (head_node -> data == search_data) {
        printf("No Node exists !\n");
    }
    else if (tail_node -> data == search_data) {
        
        while (i < node_count - 1) {
            temp_node = temp_node -> next;
            i++;
        }
        
        prev_node = temp_node -> next;
        temp_node -> next = prev_node -> next;
        prev_node -> next = NULL;
        
        free(prev_node);
        prev_node = NULL;
    }
        
    else {
        do {
            temp_node = temp_node -> next;
            count++;
            if (temp_node -> data == search_data){
                Flag = 0;
                break;
            }
        }
        while ((temp_node -> data != search_data));
        
        if (Flag == 1)
            printf("Data does not exist in the Linked List");
        else {
            
            while (j < count - 2) {
                tempp_node = tempp_node -> next;
                j++;
            }
            prev_node = tempp_node -> next;
            tempp_node -> next = prev_node -> next;
            prev_node -> next = NULL;
            
            free(prev_node);
            prev_node = NULL;
        }
    }
}

//Reversing The Circular Linked List
void rev() {
    struct node *prev_node, *curr_node, *next_node;
    prev_node = NULL;
    curr_node = next_node = head_node;
    
    tail_node -> next = NULL;
    
    while (next_node != NULL) {
        next_node = next_node -> next;
        curr_node -> next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    
    head_node = prev_node;
    
    struct node *temp_node = head_node;
    while (temp_node -> next != NULL) {
        temp_node = temp_node -> next;
    }
    tail_node = temp_node;
    tail_node -> next = head_node;
}

//Main Function
void main () {
    
    int choice;
    
    while (printf("1. Insert a node at the Beginning\n2. Insert a node at the End\n3. Insert after a particular node\n4. Insert before a particular node\n5. Insert at a particular position\n6. Delete a node at the Beginning\n7. Delete a node at the End\n8. Delete after a particular node\n9. Delete before a particular node\n10. Delete at a particular position\n11. Display Elements\n12. Reverse the Linked List\n13. Exit\nPlease Enter an Integer choice : ") && scanf(" %d",&choice) && choice != 13) {
        switch (choice) {
            
            // case 0:
            //     printf("\n");
            //     create_node();
            //     printf("\n");
            //     break;
            
            
            // case 0:
            //     printf("%d\n",nodes_count());
            //     printf("\n");
            //     break;
                
            case 1:
                printf("\n");
                insert_at_begin();
                printf("\n");
                break;
            
            case 2:
                printf("\n");
                insert_at_end();
                printf("\n");
                break;
                
            case 3:
                printf("\n");
                insert_after_node();
                printf("\n");
                break;
            
            case 4:
                printf("\n");
                insert_before_node();
                printf("\n");
                break;
                
            case 5:
                printf("\n");
                insert_at_pos();
                printf("\n");
                break;
                
            case 6:
                // printf("\n");
                delete_at_begin();
                printf("\n");
                break;
            
            case 7:
                // printf("\n");
                delete_at_end();
                printf("\n");
                break;
                
            case 8:
                // printf("\n");
                delete_after_node();
                printf("\n");
                break;
            
            case 9:
                // printf("\n");
                delete_before_node();
                printf("\n");
                break;
                
            case 10:
                // printf("\n");
                delete_at_pos();
                printf("\n");
                break;
                
            case 11:
                printf("\n");
                display();
                printf("\n");
                break;
                
            case 12:
                // printf("\n");
                rev();
                printf("\n");
                break;
             
            default:
                printf("Enter a Valid Choice !");
        }
    }
    
    printf("Thanks for Using !");
    
}
