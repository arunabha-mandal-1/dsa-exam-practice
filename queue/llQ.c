// Queue using Linked List
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototype of nodes
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// global 'front' and 'rear'
Node* rear=NULL;
Node* front=NULL;

// enqueue
void enqueue(int element);

// dequeue
int dequeue();

// print queue elements
void printQueue();

// isEmpty
bool isEmpty();

// main function of queue using linked list
int main(){
    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print elements\n");
        printf("Press any other key to quit\n");

        int choice = -1;
        printf("Enter choice : ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Enter the element you want to add : ");
            int element = -1;
            scanf("%d", &element);
            enqueue(element);
        }else if(choice==2){
            int dequeued=dequeue();
        }else if(choice==3){
            printQueue();
        }else{
            return 0;
        }
    }
    return 0;
}

// enqueue
void enqueue(int element){
    Node* n=(Node*)malloc(sizeof(Node));
    if(!n){
        printf("Memory Error.\n");
        return;
    }
    n->data=element;
    n->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=n;
    }else{
        rear->next=n;
        rear=n;
    }
    printf("%d has been added.\n", element);
}

// dequeue
int dequeue(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return -1;
    }else{
        Node* temp=front;
        int value=temp->data;
        if(front==rear){
            front=front->next;
            rear=rear->next;
        }else{
            front=front->next;
        }
        free(temp);
        temp=NULL;
        printf("%d has been removed.\n", value);
        return value;
    }
}

// print queue elements
void printQueue(){
    if(isEmpty()){
        printf("Queue is empty!\n");
    }else{
        Node* temp=front;
        printf("Queue elements are : ");
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

// isEmpty
bool isEmpty(){
    return (front==NULL && rear==NULL);
}