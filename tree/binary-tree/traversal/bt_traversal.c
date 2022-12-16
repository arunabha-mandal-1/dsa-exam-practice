// Binary tree traversal algorith and code
#include <stdio.h>
#include <stdlib.h>

// prototypes of nodes
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Utility function to create new node
Node* createNode(int element){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=element;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
} 

// There are three type of tree traversal 
    // 1. Inorder traversal
    // 2. Preorder traversal
    // 3. Postorder traversal


// Inorder traversal : Where we first visit left node then root and right nodes
void inorder_traversal(Node* root){
    if(root!=NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// Preorder traversal : Where we first visit left node then root and right nodes
void preorder_traversal(Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
// Postorder traversal : Where we first visit left node then root and right nodes
void postorder_traversal(Node* root){
    if(root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// main function
int main(){
    /*
                            1
                          /  \
                         /    \ 
                        3      2
                       / \    / \
                      4   5   6  7
                             / \
                            9   8
    */

   // pij = j-th node of level i

   // Creating nodes
   Node* p01=createNode(1); // level 0(root node)

   Node* p11=createNode(3); // level 1
   Node* p12=createNode(2); // level 1

   Node* p21=createNode(4); // level 2
   Node* p22=createNode(5); // level 2
   Node* p23=createNode(6); // level 2
   Node* p24=createNode(7); // level 2

   Node* p31=createNode(9); // level 3
   Node* p32=createNode(8); // level 3


    // linking nodes
    p01->left=p11;
    p01->right=p12;

    p11->left=p21;
    p11->right=p22;
    p12->left=p23;
    p12->right=p24;

    p23->left=p31;
    p23->right=p32;

    // inoder traversal , expected result : 4 3 5 1 9 6 8 2 7
    inorder_traversal(p01);
    printf("\n");

    // preorder traversal, expected result : 1 3 4 5 2 6 9 8 7
    preorder_traversal(p01);
    printf("\n");

    // postorder traversal, expected result : 4 5 3 9 8 6 7 2 1
    postorder_traversal(p01);
    printf("\n");


    return 0;
}