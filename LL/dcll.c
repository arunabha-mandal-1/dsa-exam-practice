// Doubly circular linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototype of nodes
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

// create a doubly circular linked list with n elements
Node* create(int n);
// insert
void insertAtBeginning(Node** head, int key);
void insertInBtwn(Node** head, int position, int key);
void insertAtEnd(Node** head, int key);
// delete
void deleteFromBeginning(Node** head);
void deleteFromEnd(Node** head);
void deleteInBtwn(Node** head, int position);
// traverse
void traverse(Node* head);
// isEmpty
bool isEmpty(Node* head);

// main function
int main(){
    Node* head=create(5);
    traverse(head);
    // insertAtBeginning(&head, 400);
    // insertAtEnd(&head, 400);
    // insertInBtwn(&head, 5, 300);
    // deleteFromBeginning(&head);
    // deleteFromEnd(&head);
    deleteInBtwn(&head,3);
    traverse(head);
    // printf("\n%d\n", head->prev->data);
    return 0;
}

// create a doubly circular linked list with n elements
Node* create(int n){
    Node* head;
    Node* tracker;
    Node* newNode;
    head=(Node*)malloc(sizeof(Node));
    head->next=NULL;
    head->prev=NULL;
    printf("Enter elements : ");
    scanf("%d", &(head->data));
    tracker=head;
    for(int i=1; i<n; i++){
        newNode=(Node*)malloc(sizeof(Node));
        scanf("%d", &(newNode->data));
        // linking
        newNode->prev=tracker;
        newNode->next=NULL;
        tracker->next=newNode;
        tracker=newNode; // moving tracker pointer
    }
    head->prev=tracker;
    tracker->next=head;
    return head;
}
// insert
void insertAtBeginning(Node** head, int key){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    if((*head)==NULL){
        newNode->next=newNode;
        newNode->prev=newNode;
    }
    newNode->next=(*head);
    newNode->prev=(*head)->prev;
    (*head)->prev->next=newNode;
    (*head)->prev=newNode;
    (*head)=newNode;
}
void insertInBtwn(Node** head, int position, int key){
    if((*head)==NULL || position==0){
        insertAtBeginning(head, key);
        return;
    }
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    Node* tracker=*head;
    int headData=(*head)->data;
    for(int i=1; (i<position)&&(tracker->next->data!=headData); i++){
        tracker=tracker->next;
    }
    if(tracker->next->data==headData){
        printf("limit exceeded!\n");
        return;
    }
    newNode->next=tracker->next;
    newNode->prev=tracker;
    tracker->next->prev=newNode;
    tracker->next=newNode;
}
void insertAtEnd(Node** head, int key){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=key;
    if((*head)==NULL){
        insertAtBeginning(head, key);
        return;
    }
    newNode->next=(*head);
    newNode->prev=(*head)->prev;
    (*head)->prev->next=newNode;
    (*head)->prev=newNode;
}
// delete
void deleteFromBeginning(Node** head){
    if((*head)==NULL){
        return;
    }
    Node* temp=(*head);
    (*head)->prev->next=(*head)->next;
    (*head)->next->prev=(*head)->prev;
    (*head)=(*head)->next;
    free(temp);
    temp=NULL;
}
void deleteFromEnd(Node** head){
    Node* lastNode=(*head)->prev;
    lastNode->prev->next=(*head);
    (*head)->prev=lastNode->prev;
    free(lastNode);
    lastNode=NULL;
}
void deleteInBtwn(Node** head, int position){
    if(position==0){
        deleteFromBeginning(head);
        return;
    }
    Node* tracker=(*head);
    int headData=(*head)->data;
    for(int i=1; (i<position)&&(tracker->next->data!=headData); i++){
        tracker=tracker->next;
    }
    if(tracker->next->data==headData){
        printf("limit exceeded!\n");
        return;
    }
    Node* nodeToBeDeleted=tracker->next;
    tracker->next=nodeToBeDeleted->next;
    nodeToBeDeleted->next->prev=tracker;
    free(nodeToBeDeleted);
    nodeToBeDeleted=NULL;
}
// traverse
void traverse(Node* head){
    Node* temp=head;
    int headData=head->data;
    printf("Elements are : ");
    printf("%d ", temp->data);
    temp=head->next;
    while(temp->data!=headData){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
// isEmpty
bool isEmpty(Node* head);