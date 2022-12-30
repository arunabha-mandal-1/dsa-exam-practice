// BST opeartions(search, insertion, deletion)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Inorder traversal : Where we first visit left node then root and right nodes
void inorder_traversal(Node* root){
    if(root!=NULL){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

// search
bool search(Node* root, int key){
    if(root==NULL){
        return false;
    }else if(key==root->data){
        return true;
    }else if(key<root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

// insertion
void insertion(Node** root, int key){
    Node* newNode=createNode(key);
    if(!newNode){ // in case memory allocation is failed
        printf("Memory error!\n");
        return;
    }

    if(*root==NULL){ // if the tree does not exist, the root node is null
        *root=newNode;
    }else{
        Node* prev=NULL; // holding the prev node after which we want to add new node
        Node* temp=*root;
        while(temp!=NULL){
            prev=temp;
            if(key==temp->data){
                printf("%d alrady exists!\n", key);
                return;
            }else if(key<temp->data){ // go to left
                temp=temp->left;
            }else{ // go to right
                temp=temp->right;
            }
        }

        // now add the newNode
        if(key<prev->data){ 
            prev->left=newNode;
        }else{
            prev->right=newNode;
        }
    }
}

// deletion
/*ALGORITHM: 
    case 1: leaf node >
        in case of leaf node just delete it and replace it with NULL
    case 2: node with one child >
        in this case replace the node with the child node
    case 3: node with both child >
        in this case replace the node with inorder successor or inorder predecessor
*/

// main function
int main(){
    /*
                           50
                          /  \
                         /    \ 
                        40     60
                       / \    / \
                      20 45  55  70
                             / \
                            52   57
    */

   // pij = j-th node of level i

   // Creating nodes
   Node* p01=createNode(50); // level 0(root node)

   Node* p11=createNode(40); // level 1
   Node* p12=createNode(60); // level 1

   Node* p21=createNode(20); // level 2
   Node* p22=createNode(45); // level 2
   Node* p23=createNode(55); // level 2
   Node* p24=createNode(70); // level 2

   Node* p31=createNode(52); // level 3
   Node* p32=createNode(57); // level 3


    // linking nodes
    p01->left=p11;
    p01->right=p12;

    p11->left=p21;
    p11->right=p22;
    p12->left=p23;
    p12->right=p24;

    p23->left=p31;
    p23->right=p32;

    // inoder traversal , expected result : 20 40 45 50 52 55 57 60 70
    // inorder_traversal(p01);
    // printf("\n");

    // int searchKey=58;
    // if(search(p01, searchKey)){
    //     printf("%d exists in the BST\n", searchKey);
    // }else{
    //     printf("%d does not exist in the BST\n", searchKey);
    // }

    // insertion(&p01, 60);
    // inorder_traversal(p01);

    printf("%s\n", search(p01, 52)?"Found":"Not found");
    return 0;
}