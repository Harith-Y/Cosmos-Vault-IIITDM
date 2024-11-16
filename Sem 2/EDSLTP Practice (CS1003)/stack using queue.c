#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL, *front1=NULL, *front2=NULL, *rear1=NULL, *rear2=NULL;
void enqueue(struct node *front, struct node *rear, int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->dtaa=data;
    temp->next=NULL;
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    }
int dequeue(struct node *front, struct node *rear){
    int x;
    if(front==NULL&& rear==NULL){
        print("No node exist");
    }
    else if(front==rear){
        struct node *temp=front;
        x=temp->data;
        free(temp);
        front=NULL;
        rear=NULL;
    }else{
        struct node *temp=front;
        front=front->next;
        x=temp->data;
        free(temp);
    }
    return x;
}
void printlist(struct node *head){
    while(head!=NULL){
        printf("%d", head->data);
        head=head->next;
    }
}
void main(){
    int data, a;
    struct node *temp=NULL;
    do{
        printf("Enter the data:\n");
        scanf("%d", &data);
        enqueue(front1, rear1, data);
        if(front2!=NULL){
            enqueue(front1, rear1, dequeue(front2, rear2))
        }
        temp=front1;
        front1=front2;
        front2=temp;
        temp=rear1;
        rear1=rear2;
        rear2=temp;
        printf("press 1 for continue.\npress 2 for stop.\n");
        scanf("%d", &a);
    }while(a!=0);
}
