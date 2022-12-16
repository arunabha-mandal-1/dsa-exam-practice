// Implementation of Threaded Binary Tree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototype of double threaded node
typedef struct NodeDouble{
    int data;
    struct Node* left;
    struct Node* right;
    bool rightThread;
    bool leftThreaded;
}NodeDouble;

// prototype of single threaded node
typedef struct NodeSingle{
    int data;
    struct Node* left;
    struct Node* right;
    bool rightThread;
}NodeSingle;

// to find leftmost node in a tree rooted with n
NodeSingle* leftMost(NodeSingle* n){
    if(n==NULL){return NULL;}
    while(n->left!=NULL){
        n=n->left;
    }
    return n;
}

// inorder traversal
void inorder_traversal(NodeSingle* root){
    NodeSingle* cur=leftMost(root);
    while(cur!=NULL){

        // if this node is threaded, go to inorder successor
        if(cur->rightThread){
            cur=cur->right;
        }else{ // else go to the leftmost child in right subtree
            cur=leftMost(cur->right);
        }
    }
}

// main function
int main(){

    // could not implement this on code yet
    return 0;
}