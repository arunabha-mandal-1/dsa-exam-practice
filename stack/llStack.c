// Stack using linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// prototype of nodes
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// global 'top' variable
Node* top=NULL;

// push
void push(int element);

// pop
int pop();

// isEmpty
bool isEmpty();

// print stack elements in reverse order
void printStack();

// main function
int main(){

    printStack();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("First popped element %d\n", pop());
    printf("Second popped element %d\n", pop());

    printStack();

    return 0;
}

// push
void push(int element){
    Node* n=(Node*)malloc(sizeof(Node));
    if(!n){printf("Memory Error.\n"); return;}
    n->data=element;
    n->next=top;
    top=n;
}

// pop
int pop(){
    if(isEmpty()){
        printf("Stack Undreflow.\n");
        return -1;
    }else{
        Node *temp=top;
        int value=temp->data;
        top=top->next;
        free(temp);
        temp=NULL;
        return value;
    }
}

// isEmpty
bool isEmpty(){
    return (top==NULL);
}

// print stack elements in reverse order
void printStack(){
    if(isEmpty()){
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are : ");
    Node* temp=top;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}