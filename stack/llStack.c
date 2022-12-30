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

// main function of stack using linked list
int main(){
    while(1){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print elements\n");
        printf("Press any other key to quit\n");

        int choice = -1;
        printf("Enter choice : ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Enter the element you want to add : ");
            int element = -1;
            scanf("%d", &element);
            push(element);
        }else if(choice==2){
            int popped=pop();
        }else if(choice==3){
            printStack();
        }else{
            return 0;
        }
    }
    return 0;
}

// push
void push(int element){
    Node* n=(Node*)malloc(sizeof(Node));
    if(!n){printf("Memory Error.\n"); return;}
    n->data=element;
    n->next=top;
    top=n;
    printf("%d has been added.\n", element);
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
        printf("%d has been removed.\n", value);
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
    printf("Stack elements are(top to bottom) : ");
    Node* temp=top;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}