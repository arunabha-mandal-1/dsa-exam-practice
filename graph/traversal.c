// graph traversal > bfs and dfs
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

// isEmpty
bool isEmpty(){
    return (front==NULL && rear==NULL);
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

// bfs
void bfs(int a[8][8], int start, int* visited){
    visited[start]=1;
    printf("%d ", start);
    enqueue(start);
    while(!isEmpty()){
        int u=dequeue();
        for(int i=0; i<8; i++){
            if(a[u][i]==1 && visited[i]==0){
                printf("%d ", i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}
// dfs
void dfs(int a[8][8], int u, int* visited){
    printf("%d ", u);
    visited[u]=1;
    for(int i=0; i<8; i++){
        if(a[u][i]==1 && visited[i]==0){
            dfs(a,i,visited);
        }
    }
}
// main function
int main(){
    int a[8][8]={
        {0,1,1,0,0,0,0,0},
        {1,0,0,1,0,1,0,1},
        {1,0,0,0,1,0,1,1},
        {0,1,0,0,0,1,0,0},
        {0,0,1,0,0,0,1,0},
        {0,1,0,1,0,0,0,1},
        {0,0,1,0,1,0,0,1},
        {0,1,1,0,0,0,0,0}
    };
    int visitedBfs[8]={0,0,0,0,0,0,0,0};
    printf("BFS : "); bfs(a,0,visitedBfs); printf("\n");

    int visitedDfs[8]={0,0,0,0,0,0,0,0};
    printf("DFS : "); dfs(a,0,visitedDfs); printf("\n");
    
    return 0;
}