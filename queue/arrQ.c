// Queue using Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 10

// prototype of queue
typedef struct Queue{
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

// print Queue elements
void printQueue(Queue* q);

// main function
int main(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=-1;
    q->size=maxsize;
    q->array=(int*)malloc((sizeof(int))*q->size);

    printQueue(q);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    // enqueue(q,40);
    // enqueue(q,50);
    // enqueue(q,60);
    // enqueue(q,70);
    // enqueue(q,80);
    // enqueue(q,90);
    // enqueue(q,100);
    // enqueue(q,110); // overflow

    // dequeue(q);
    // enqueue(q,555);

    dequeue(q);
    dequeue(q);
    enqueue(q,111);
    // dequeue(q);

    printQueue(q);

    // printf("%d\n", q->array[-1]); // garbage value
    return 0;
}

// enqueue
void enqueue(Queue* q, int element){
    if(isFull(q)) {printf("Queue is full!\n");}
    else {q->array[++(q->rear)]=element;}
}

// dequeue
int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    else{
        return q->array[(q->front)++];
    }
}

// isFull
bool isFull(Queue* q){
    if(q->front!=-1 && (q->front==q->rear)){
        q->front=q->rear=-1;
        return false;
    }else if(q->rear==q->size-1){
        return true;
    }else{
        return false;
    }
}

// isEmpty
bool isEmpty(Queue* q){
    return (q->front==-1 && q->rear==-1);
}

// print Queue elements
void printQueue(Queue* q){
    if(q->front==q->rear){
        printf("Queue is empty!\n");
    }else{
        printf("Queue elements are : ");
        for(int i=q->front+1; i<=q->rear; i++){
            printf("%d ", q->array[i]);
        }
        printf("\n");
    }
}