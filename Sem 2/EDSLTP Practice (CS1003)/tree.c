#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;
};
struct node *create(int data){
struct node *temp = (struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->right=NULL;
temp->left=NULL;
return temp;
}
struct node *insert(struct node *node, int data){
if(node==NULL){
    return create(data);
}
else if(data>node->data){
    node->right=insert(node->right, data);
}
else if(data<node->data){
    node->left=insert(node->left, data);
}
return node;
}
void main(){
struct node *root=NULL;
root=insert(root,20);
printf("%d\n", root);
root=insert(root,15);
printf("%d\n", root);
root=insert(root,18);
printf("%d\n\n", root);
root=insert(root,22);
printf("%d", root);
}
