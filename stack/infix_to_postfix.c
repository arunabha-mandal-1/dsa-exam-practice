// Infix to Postfix using Stack Data Structure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// prototype of nodes
typedef struct Node{
    char data;
    struct Node* next;
}Node;

// global 'top' variable
Node* top=NULL;

// push
void push(char element);

// pop
char pop();

// isEmpty
bool isEmpty();

// top element of stack
char stackTop();

// print stack elements in reverse order
void printStack();

// checking if the parenthesis is opening parenthesis
bool isOpening(char ch);

// checking if the parenthesis is closing parenthesis
bool isClosing(char ch);

// checking the character is an operand
bool isOperand(char ch);

// checking the character is an operator
bool isOperator(char ch);

// precedence of operators
int prec(char ch);

// final function to convert infix expression to postfix expression
char* inToPost(char* str);

// main function of infix to postfix conversion
int main(){
    char infix[100];
    printf("Enter the string : ");
    scanf("%[^\n]s", infix);
    char *postfix=inToPost(infix);
    printf("Postfix expression is %s\n", postfix);
    return 0;
}

// push
void push(char element){
    Node* n=(Node*)malloc(sizeof(Node));
    if(!n){printf("Memory Error.\n"); return;}
    n->data=element;
    n->next=top;
    top=n;
}

// pop
char pop(){
    if(isEmpty()){
        printf("Stack Undreflow.\n");
        return '!';
    }else{
        Node *temp=top;
        char value=temp->data;
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

// top element of stack
char stackTop(){
    if(!isEmpty()){
        return top->data;
    }
    return '#';
}

// checking if the parenthesis is opening parenthesis
bool isOpening(char ch){
    return (ch=='(' || ch=='{' || ch=='[');
}

// checking if the parenthesis is closing parenthesis
bool isClosing(char ch){
    return (ch==')' || ch=='}' || ch==']');
}

// checking the character is an operand
bool isOperand(char ch){
    return ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'));
}

// checking the character is an operator
bool isOperator(char ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
}

// precedence of operators
int prec(char ch){
    if(ch=='+'||ch=='-') {return 1;}
    else if(ch=='*'||ch=='/') {return 2;}
    else if(ch=='^') {return 3;}
    return -1;
}

// final function to convert infix expression to postfix expression
char* inToPost(char* str){
    int len=strlen(str);
    char* postfix=(char*)calloc(len+1, sizeof(char));
    int i=0; // tracking infix
    int p=0; // tracking postfix

    while(i<len){
        char currChar=str[i];
        if(isOpening(currChar)){
            push(currChar);
            i++;
        }else if(isOperand(currChar)){
            postfix[p]=currChar;
            p++;
            i++;
        }else if(isClosing(currChar)){
            while(!isEmpty() && !isOpening(stackTop())){
                postfix[p]=pop();
                p++;
            }
            if(isEmpty() && !isOpening(stackTop())){
                printf("Invalid Expression!\n");
                return "!!";
            }else{
                pop();
            }
            i++;
        }else{
            if(prec(currChar)>prec(stackTop())){
                push(currChar);
                i++;
            }else{
                postfix[p]=pop();
                p++;
            }
        }
    }
    // pop and output token until the stack is empty
    while(!isEmpty()){
        postfix[p++]=pop();
    }
    postfix[p]='\0';
    return postfix;
}