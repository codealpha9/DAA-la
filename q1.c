// Write a program to construct a binary tree to support the following operations.
// Assume no duplicate elements while constructing the tree.

// i. Given a key, perform a search in the binary search tree. If the key is found
// then display “key found” else insert the key in the binary search tree.

// ii. Display the tree using inorder, preorder and post order traversal method

#include <stdio.h>
#include<stdlib.h>
typedef struct node* node_ptr;
struct node{
    int data;
    node_ptr lchild;
    node_ptr rchild;
}node;
node_ptr root=NULL;
node_ptr insert(int element ,node_ptr node){
    node_ptr temp;
    if(node==NULL){
        temp=(node_ptr)malloc(sizeof(node));
        temp->data=element;
        temp->lchild=NULL;
        temp->rchild=NULL;
        if(root==NULL)
            root=temp;
        return temp;

    }
    else if(element < node->data){
        node->lchild=insert(element,node->lchild);
        return node;
    }
    else if (element > node->data){
        node->rchild=insert(element,node->rchild);
        return node;

    }
    else{
        printf("duplicate element found");
        return node;
    }

}
void inorder(node_ptr node){
    if(node == NULL){
        return;
    }
    inorder(node->rchild);
    printf(" %d ",node->data);
    inorder(node->lchild);
}
void search(int number,node_ptr node){
    if(node == NULL)
        printf("element not found\n");

    if(number == node ->data){
        printf("element found\n");
    }
    else if(number > node ->data){
        search(number,node->rchild);
    }
    else if (number< node->data)
    {
        search(number,node->lchild);
    }
    
}

void main(){
    int element;
    int find;
    while(1){
        printf("enter elements to enter : ");
        scanf("%d",&element);
        insert(element,root);
        printf("enter 0 to continue, anythong else to stop : ");
        scanf("%d",&element);
        if(element)
            break;
    }
    inorder(root);
    scanf("%d",&find);
    search(find,root);
    
}