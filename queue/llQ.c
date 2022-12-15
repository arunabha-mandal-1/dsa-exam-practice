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

// main function
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // Node* temp=front; // for debug

    printQueue();

    dequeue();
    dequeue();
    dequeue();

    // printf("%d\n", rear->data);
    printQueue();
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