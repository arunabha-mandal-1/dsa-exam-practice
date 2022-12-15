// Circular Queue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 5

// prototype of queue
typedef struct Queue{
    int data;
    int size;
    int front;
    int rear;
    int* array;
}Queue;

// enqueue
void enqueue(Queue* q, int element);

// dequeue
int dequeue(Queue* q);

// isFull
bool isFull(Queue* q);

// isEmpty
bool isEmpty(Queue* q);

// print queue elements
void printQueue(Queue* q);

// main function
int main(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    q->size=maxsize;
    q->array=(int*)malloc((sizeof(int))*(q->size));

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    dequeue(q);
    enqueue(q,60);
    printQueue(q);

    return 0;
}

// enqueue
void enqueue(Queue* q, int element){
    if(isFull(q)){
        printf("Queue is full!\n");
    }else{
        q->rear=(q->rear+1)%q->size;
        q->array[q->rear]=element;
        if(q->front==-1){
            q->front=q->rear;
        }
    }
}

// dequeue
int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }else{
        int value=q->array[q->front];
        if(q->front==q->rear){
            q->front=q->rear=-1;
        }else{
            q->front=(q->front+1)%q->size;
        }
        return value;
    }
}

// isFull
bool isFull(Queue* q){
    return ((q->rear+1)%q->size==q->front);
}

// isEmpty
bool isEmpty(Queue* q){
    return (q->rear==-1 && q->front==-1);
}

// print queue elements
void printQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty! Nothing to print!\n");
    }else{
        printf("Queue elements are : ");
        if(q->rear==q->front){ // only one element
            printf("%d\n", q->array[q->front]);
        }else if(q->rear<q->front){
            for(int i=q->front; i<q->size; i++){
                printf("%d ", q->array[i]);
            }
            for(int j=0; j<=q->rear; j++){
                printf("%d ", q->array[j]);
            }
            printf("\n");
        }else{
            for(int k=q->front; k<=q->rear; k++){
                printf("%d ", q->array[k]);
            }
            printf("\n");
        }
    }
}