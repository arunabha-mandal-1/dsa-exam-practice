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

// main function of stack using array
int main(){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    s->size=maxsize;
    s->array=(int*)malloc((sizeof(int))*(s->size));
    s->top=-1;

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
            push(s, element);
        }else if(choice==2){
            int popped=pop(s);
        }else if(choice==3){
            printStack(s);
        }else{
            return 0;
        }
    }
    return 0;
}

// push
void push(Stack* s, int data){
    if(!isFull(s)){
        s->array[++(s->top)]=data;
        printf("%d has been added.\n", data);
    }else{
        printf("Stack Overflow!\n");
    }
}

// pop
int pop(Stack* s){
    if(!isEmpty(s)){
        int value=s->array[(s->top)--];
        printf("%d has been removed.\n", value);
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