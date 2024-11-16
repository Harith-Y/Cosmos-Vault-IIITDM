//Harith Y, CS23I1027

#include<stdio.h>
#include<stdlib.h>


//Defining a Structure node for a Doubly Linked List
struct node
{
	int data;
	struct node *next;
}; 
struct node *head_node = NULL;


//Creating a Node in the Singly Linked List
void create_node()
{
	struct node *new_node, *temp_node = head_node;
	new_node = (struct node *) malloc(sizeof(struct node));
	printf("Please enter the value : ");
	scanf(" %d", &new_node -> data);
	new_node -> next = NULL;
	
	if (head_node == NULL)
	{
		temp_node = new_node;
		temp_node = head_node;
	}
	
	else
	{
		temp_node -> next = new_node;
		temp_node = temp_node -> next;
	}
}


//Displaying all the elements in the Singly Linked List.
void display()
{
	struct node *temp_node = head_node;
	
	if (head_node == NULL)
		printf("The Linked List is Empty ! \n");
	else
	{
		while (temp_node != NULL)
		{
			printf("%d\n",temp_node -> data);
			temp_node = temp_node -> next;
		}
		printf("\n");
	}
}


//Adding a node to the beginning of the Singly Linked List
void add_node_to_beginning()
{
	struct node *new_node;
	new_node = (struct node *) malloc(sizeof(struct node));
	printf("Please enter the value : ");
	scanf(" %d", &new_node -> data);
	new_node -> next = NULL;
	new_node -> next = head_node;
	head_node = new_node;
}


//Adding a node to the End of the Singly Linked List
void add_node_to_end()
{
	struct node *new_node, *temp_node = head_node;
	new_node = (struct node *) malloc(sizeof(struct node));
	printf("Please enter the value : ");
	scanf(" %d", &new_node -> data);
	
	
	if (head_node == NULL)
	{
		new_node -> next = head_node;
		head_node = new_node;
	}
	
	else
	{
		new_node -> next = NULL;
		while (temp_node -> next != NULL)
		{
			temp_node = temp_node -> next;
		}
	
		temp_node -> next = new_node;
	}
}

//Finding the number of nodes in the Singly Linked List
int node_count()
{
	struct node *temp_node = head_node;
	int count = 0;
	
	if (head_node == NULL)
		return count;
	else
	{
		while (temp_node != NULL)
		{
			temp_node = temp_node -> next;
			count++;
		}
	
		return count;	
	}
}

//Adding a node after a particular position in the Singly Linked List
void add_node_after_pos()
{
	int pos, i=1;
	printf("Enter the position after which you want to insert the node : ");
	scanf(" %d", &pos);
	int nodes_count = node_count();
	
	if (pos>nodes_count)
		printf("Please enter a valid Position !\n");
	
	else
	{
		struct node *new_node, *temp_node = head_node;
		new_node = (struct node *) malloc(sizeof(struct node));
		printf("Please enter the value : ");
		scanf(" %d", &new_node -> data);
		
		while (i<pos)
		{
			temp_node = temp_node -> next;
			i++;
		}
		
		new_node -> next = temp_node -> next;
		temp_node -> next = new_node;
	}
}

//Deleting the first node in the Singly Linked List
void del_node_at_beginning()
{
	if (head_node == NULL)
		printf("The Linked List is Empty ! \n");
	
	else if (head_node -> next == NULL)
	{
		printf("The deleted Node Value is %d",head_node -> data);
		free(head_node);
		head_node = NULL;
	}
	
	else
	{
		struct node *temp_node = head_node;
		head_node = temp_node -> next;
		free(temp_node);
		temp_node = NULL;
	}


}

//Deleting the last node in the Singly Linked List
void del_node_at_end()
{
	//No Node present in the Linked List
	if (head_node == NULL)
		printf("The Linked List is Empty ! \n");
	
	//First element of the Linked List gets deleted
	else if (head_node -> next == NULL)
	{
		printf("The deleted Node Value is %d",head_node -> data);
		free(head_node);
		head_node = NULL;
	}
	
	
	else
	{
		struct node *temp_node = head_node, *prev_node;
		
		while (temp_node -> next != NULL)
		{
			prev_node = temp_node;
			temp_node = temp_node -> next;
		}
		prev_node -> next = NULL;
		free(temp_node);
		temp_node = NULL;
	}
}

//Deleting a node at a particular position in the Singly Linked List
void del_node_at_pos()
{
	int pos, i=1;
	printf("Enter the position at which you want to delete the node : ");
	scanf(" %d", &pos);
	int nodes_count = node_count();
	
	if (pos>nodes_count)
		printf("Please enter a valid Position !\n");
	
	else
	{
		struct node *temp_node = head_node, *prev_node;
		
		while (i<pos-1)
		{
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

//Reversing a Singly Linked List
void rev_linked_list()
{
	struct node *prev_node, *curr_node, *next_node;
	prev_node = NULL;
	curr_node = next_node = head_node;
	
	while (next_node != NULL)
	{
		next_node = next_node -> next;
		curr_node -> next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}
	
	head_node = prev_node;
}

//Displaying all the elements in the reverse order of a Singly Linked List
void display_rev()
{
	rev_linked_list();
	struct node *temp_node = head_node;
	while (temp_node != NULL)
	{
		printf("%d\n", temp_node -> data);
		temp_node = temp_node -> next;
	}
	printf("\n");
}

void main()
{

	int choice;
	while (printf("\n1. Create a Node in the Linked List \n2. Display values of the Linked List \n3. Adding a Node to the Linked List \n4. Displaying the number of Nodes in the Linked List \n5. Delete a Node in the Linked List \n6. Exit the Program \nPlease enter an integer choice : ") && scanf(" %d",&choice) && choice != 6)
	
	{
		switch (choice)
		{
			case 1:
				//Creating a Node
				
				printf("\n");
				create_node();
				printf("\n");
				break;
			case 2:
				//Displaying the elements of the Linked List
				
				int display_choice;
				while (printf("\n1. Display Values in the Linked List in Given Order \n2. Display values of the Linked List in Reverse Order \n3. Exit the Node Elements Displaying Sub-Program \nPlease enter an integer choice : ") && scanf(" %d",&display_choice) && display_choice != 3)
				{
					switch (display_choice)
					{
						case 1:
							//Displaying the elements of the Linked List in the Given Order
							printf("\n");
							display();
							printf("\n");
							break;
						case 2:
							//Displaying the elements of the Linked List in Reverse Order
							
							printf("\n");
							display_rev();
							printf("\n");
							break;
						default:
							printf("Please enter a Valid Input !\n");		
					}
				}
				break;
				
			case 3:
				//Adding a Node to the Linked List
				
				int add_choice;
				while (printf("\n1. Adding a Node to the beginning of the Linked List \n2. Adding a Node at the end of the Linked List \n3. Adding a Node at a particular Position of the Linked List \n4. Exit the Node Addition Sub-Program \nPlease enter an integer choice : ") && scanf(" %d",&add_choice) && add_choice != 4)
				{
					switch (add_choice)
					{
						case 1:
							//Adding A Node to the beginning of the Linked List
							
							printf("\n");
							add_node_to_beginning();
							printf("\n");
							break;
						case 2:
							//Adding a Node to the end of the Linked List
							
							printf("\n");
							add_node_to_end();
							printf("\n");
							break;
						case 3:
							//Adding A Node to a parricular position in the Linked List
							
							printf("\n");
							add_node_after_pos();
							printf("\n");
							break;
						default:
							printf("Please enter a Valid Input !\n");		
					}
				}
				break;
				
			case 4:
				//Finding the number of Nodes in the Linked List
				
				printf("\nThe number nodes in the Linked List = %d\n\n",node_count());
				break;
			case 5:
				//Deleting A Node of the Linked List
				
				int del_choice;
				while (printf("\n1. Delete a Node at the beginning of the Linked List \n2. Delete a Node at the end of the Linked List \n3. Delete a Node at a particular Position of the Linked List \n4. Exit the Node Deletion Sub-Program \nPlease enter an integer choice : ") && scanf(" %d",&del_choice) && del_choice != 4)
				{
					switch (del_choice)
					{
						case 1:
							//Deleting A Node at the beginning of the Linked List
							
							del_node_at_beginning();
							printf("\n");
							break;
						case 2:
							//Deleting a Node at the end of the Linked List
							
							del_node_at_end();
							printf("\n");
							break;
						case 3:
							//Deleting a Node at a particular Position
							
							del_node_at_pos();
							printf("\n");
							break;
						default:
							printf("Please enter a Valid Input !\n");		
					}
				}
				break;
			default:
				printf("Please enter a Valid Input !\n");		
		}

	}
	printf("\nThanks for using !\n\n");
}

