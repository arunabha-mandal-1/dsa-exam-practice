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

//Singly linked list Main function
int main(){
    Node* head=NULL;
    while(1){
        printf("\n1. Create a linked list.\n");
        printf("2. Insert a node.\n");
        printf("3. Delete a node.\n");
        printf("4. Reverse the linked list.\n");
        printf("5. Print linked list elements.\n");
        printf("Press any other key to quit.\n");

        int choice=-1;
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Number of elements you want to add : ");
            int no=-1;
            scanf("%d", &no);
            head=create(no);
        }else if(choice==2){
            int element=-1, position=-1;
            printf("Enter the element : "); scanf("%d", &element);
            printf("Enter the position : "); scanf("%d", &position);
            insert(&head, position, element);
        }else if(choice==3){
            int position=-1;
            printf("Enter the position you want to delete a node from : ");
            scanf("%d", &position);
            delete(&head, position);
        }else if(choice==4){
            reverse(&head);
            printf("Reversed linked list ->\n");
            printLL(head);
            return 0;
        }else if(choice==5){
            printLL(head);
        }else{
            return 0;
        }
    }
    return 0;
}

// Create a linked list with n elements
Node* create(int n){
    if(n<=0){
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
    if(temp==NULL){
        printf("Linked list is empty.\n");
        return;
    }
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
