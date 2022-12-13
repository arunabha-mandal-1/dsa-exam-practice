// Doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototype of nodes
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

// create
Node* create(int n);
// delete
void delete(Node** head, int position);
// insert
void insert(Node** head, int position, int key);
// traverse
void traverse1(Node* head);
void traverse2(Node* head);
// isEmpty
bool isEmpty(Node* head);
// last node
Node* lastNode(Node* head);

// main function
int main(){
    Node* head=create(5);
    traverse1(head);
    insert(&head, 4, 50);
    // traverse2(head);
    traverse1(head);

    return 0;
}
// create
Node* create(int n){
    if(n==0) return NULL;
    Node* head;
    Node* tracker;
    Node* newNode;
    printf("enter elements : ");
    head=(Node*)malloc(sizeof(Node));
    scanf("%d", &(head->data));
    head->next=NULL;
    head->prev=NULL;
    tracker=head;
    for(int i=1; i<n; i++){
        newNode=(Node*)malloc(sizeof(Node));
        scanf("%d", &(newNode->data));
        // linking
        newNode->prev=tracker;
        newNode->next=NULL;
        tracker->next=newNode;
        tracker=newNode;
    }
    return head;
}
// delete
void delete(Node** head, int position){
    if(*head==NULL) return;
    Node* tracker=NULL;
    if(position==0){
        tracker=*head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(tracker);
        tracker=NULL;
        return;
    }
    tracker=*head;
    // go to the node you want to delete
    for(int i=1; (i<=position)&&(tracker!=NULL); i++){
        tracker=tracker->next;
    }
    if(tracker==NULL){
        return;
    }
    tracker->prev->next=tracker->next;
    if(tracker->next!=NULL){
        tracker->next->prev=tracker->prev;
    }
    free(tracker);
    tracker=NULL;
}
// insert
void insert(Node** head, int position, int key){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    if(position==0){
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
        return;
    }
    Node* tracker=*head;
    for(int i=1; (i<position)&&(tracker->next!=NULL); i++){
        tracker=tracker->next;
    }
    newNode->next=tracker->next;
    newNode->prev=tracker;
    if(tracker->next!=NULL){
        tracker->next->prev=newNode;
    }
    tracker->next=newNode;
    return;
}
// traverse from start to end
void traverse1(Node* head){
    Node* temp=head;
    printf("elements are : ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
// traverse from end to start
void traverse2(Node* head){
    Node* temp=lastNode(head);
    printf("elements are : ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
// isEmpty
bool isEmpty(Node* head){
    return(head==NULL);
}
// last node
Node* lastNode(Node* head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}