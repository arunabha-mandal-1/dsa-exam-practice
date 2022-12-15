// Stack using Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// max no of stack elements
#define maxsize 10

// prototype
typedef struct Stack{
    int size;
    int top;
    int* array;
}Stack;

// push
void push(Stack* s, int data);

// pop
int pop(Stack* s);

// isEmpty
bool isEmpty(Stack* s);

// isFull
bool isFull(Stack* s);

// print elements
void printStack(Stack* s);

// main function
int main(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->size=maxsize;
    s->array=(int*)malloc((sizeof(int))*(s->size));
    s->top=-1;

    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    
    printf("First popped element %d\n", pop(s));
    printf("Second popped element %d\n", pop(s));
    
    printStack(s);

    return 0;
}

// push
void push(Stack* s, int data){
    if(!isFull(s)){
        s->array[++(s->top)]=data;
    }else{
        printf("Stack Overflow!\n");
    }
}

// pop
int pop(Stack* s){
    if(!isEmpty(s)){
        int value=s->array[(s->top)--];
        return value;
    }else{
        printf("Stack Underflow!\n");
        return -1;
    }
}

// isEmpty
bool isEmpty(Stack* s){
    return (s->top==-1);
}

// isFull
bool isFull(Stack* s){
    return (s->top==s->size-1);
}

// print elements
void printStack(Stack* s){
    printf("Stack elements are : ");
    if(isEmpty(s)){
        printf("Stack is Empty.\n");
    }else{
        for(int i=0; i<=s->top; i++){
            printf("%d ", s->array[i]);
        }
        printf("\n");
    }
}