// Breadth First Search implemented using Queue
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

// isEmpty
bool isEmpty();

// Breadth First Search
void bfs(int arr[6][6], int s);

// main function
int main(){
    int A[6][6]={
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,0,1,0},
        {0,1,0,0,1,1},
        {0,0,1,1,0,1},
        {0,0,1,1,0,0}
    };

    bfs(A, 0);
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

// isEmpty
bool isEmpty(){
    return (front==NULL && rear==NULL);
}

// Breadth First Search
void bfs(int arr[6][6], int s){
    int visited[6]={0,0,0,0,0,0};
    printf("%d ", s);
    visited[s]=1;
    enqueue(s);
    while(!isEmpty()){
        int u=dequeue();
        for(int i=0; i<6; i++){
            if(arr[u][i]==1 && visited[i]==0){
                printf("%d ", i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}