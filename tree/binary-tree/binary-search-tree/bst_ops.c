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

// preorder traversal
void preorder_traversal(Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// postorder traversal
void postorder_traversal(Node* root){
    if(root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

// Inorder traversal
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

// creation of binary search tree
void createBST(Node** root, int n){
    printf("Enter %d keys : ", n);
    for(int i=0; i<n; i++){
        int value=-1;
        scanf("%d", &value);
        insertion(root, value);
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
Node* succ(Node* curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* delete(Node* root, int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=delete(root->left, key);
    }else if(key>root->data){
        root->right=delete(root->right, key);
    }else{
        if(root->left=NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }else{
            Node* succNode=succ(root);
            root->data=succNode->data;
            root->right=delete(root->right, succNode->data);
        }
    }
    return root;
}

// main function of binary search tree
int main(){
    Node* root=NULL;
    while(1){
        printf("\n1. Create a binary search tree\n");
        printf("2. Insert an element in the BST\n");
        printf("3. Delete an element from the BST\n");
        printf("4. Inorder traversal\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("Press any other key to exit\n");

        int choice = -1;
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice==1){
            root=NULL;
            printf("How many elements you want to add? ");
            int no=-1; scanf("%d", &no);
            createBST(&root, no);
        }else if(choice==2){
            int element=-1;
            printf("Enter the element you want to add : ");
            scanf("%d", &element);
            insertion(&root, element);
        }else if(choice==3){
            int element=-1;
            printf("Enter the element you want to delete : ");
            scanf("%d", &element);
            root=delete(root, element);
        }else if(choice==4||choice==5||choice==6){
            if(root==NULL){
                printf("Tree is empty!\n");
            }else{
                if(choice==4){
                    printf("Inorder traversal : ");
                    inorder_traversal(root);
                    printf("\n");
                }else if(choice==5){
                    printf("Preorder traversal : ");
                    preorder_traversal(root);
                    printf("\n");
                }else if(choice==6){
                    printf("Postorder traversal : ");
                    postorder_traversal(root);
                    printf("\n");
                }
            }
        }
        else{
            return 0;
        }
    }
    return 0;
}