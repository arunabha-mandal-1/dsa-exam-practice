// Parenthesis matching using stack
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

// print stack elements in reverse order
void printStack();

// checking if the parenthesis is opening parenthesis
bool isOpening(char ch);

// checking if the parenthesis is closing parenthesis
bool isClosing(char ch);

// checking is two parenthesises match
bool isTwoMatched(char par1, char par2);

// checking if parenthesises are matching in the given expressions
bool isMatched(char* str){
    int len=strlen(str);
    int i=0;
    while(i<len){
        char currChar=str[i];
        if(isOpening(currChar)){
            push(currChar);
        }else if(isClosing(currChar)){
            char openingChar=pop();
            if(!isTwoMatched(openingChar, currChar)){
                printf("Not matched!\n");
                return false;
            }
        }
        i++;
    }
    if(isEmpty()){
        printf("Matched!\n");
        return true;
    }else{
        printf("Not matched!\n");
        return false;
    }
}

// main function
int main(){
    printf("Enter expression : ");
    char str[100];
    scanf("%[^\n]s", str);
    isMatched(str);
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
        // printf("Stack Undreflow.\n"); // not required here
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

// checking if the parenthesis is opening parenthesis
bool isOpening(char ch){
    return (ch=='(' || ch=='{' || ch=='[');
}

// checking if the parenthesis is closing parenthesis
bool isClosing(char ch){
    return (ch==')' || ch=='}' || ch==']');
}

// checking is two parenthesises match
bool isTwoMatched(char par1, char par2){
    return (par1=='(' && par2==')')||(par1=='{' && par2=='}')||(par1=='[' && par2==']');
}