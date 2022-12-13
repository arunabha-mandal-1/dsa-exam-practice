// Singly linked list
#include <stdio.h>
#include <stdlib.h>

// Prototype for nodes
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// Create a linked list with n elements
Node* create(int n);
// Traverse
void printLL(Node* head);
// Deletion
void delete(Node** head, int position);
// Insertion
void insert(Node** head, int position, int key);
// Reverse
void reverse(Node** head);
// isEmpty
int isEmpty(Node* head);

// Main function
int main(){
    Node* head=create(5);
    printLL(head);
    // delete(&head, 1);
    // insert(&head, 6, 50);
    reverse(&head);
    printLL(head);
    return 0;
}

// Create a linked list with n elements
Node* create(int n){
    if(n==0){
        return NULL;
    }
    Node* head;
    Node* tracker;
    Node* newNode;

    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    printf("Enter elements : ");
    scanf("%d", &(head->data));

    tracker=head;
    for(int i=1; i<n; i++){
        newNode=(Node*)malloc(sizeof(Node));
        scanf("%d", &(newNode->data));
        newNode->next=NULL;

        tracker->next=newNode;
        tracker=newNode;
    }
    return head;
}
// Traverse
void printLL(Node* head){
    Node* temp=head;
    printf("Elements are : ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
// Deletion
void delete(Node** head, int position){
    if(*head==NULL){
        return;
    }
    if(position==0){
        Node* temp=*head;
        *head=(*head)->next;
        free(temp);
        temp=NULL;
        return;
    }

    // stop one node ahead of the node you want to delete
    Node* tracker=*head;
    for(int i=1;(i<position)&&(tracker->next);i++){
        tracker=tracker->next;
    }
    Node* temp=tracker->next;
    if(temp==NULL){
        printf("limit exceeded!\n");
        return;
    }
    tracker->next=temp->next;
    free(temp);
    temp=NULL;
}
// Insertion
void insert(Node** head, int position, int key){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    newNode->next=NULL;
    if(*head==NULL) {*head=newNode; return;}
    if(position==0){
        newNode->next=*head;
        *head=newNode;
        return;
    }

    // stop one node ahead you want to add element
    Node* tracker=*head;
    for(int i=1; (i<position)&&(tracker); i++){
        tracker=tracker->next;
    }
    if(tracker==NULL){
        printf("limit exceed!\n");
        return;
    }
    newNode->next=tracker->next;
    tracker->next=newNode;
}
// Reverse
void reverse(Node** head){
    Node* prev=NULL;
    Node* curr=*head;
    Node* next=NULL;
    while(curr!=NULL){
        // store next
        next=curr->next;
        // reverse current node's pointer
        curr->next=prev;
        // move pointer one node ahead
        prev=curr;
        curr=next;
    }
    *head=prev;
}
// isEmpty
int isEmpty(Node* head){
    return (head==NULL);
}
