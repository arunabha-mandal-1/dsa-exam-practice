// Queue using Array
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 5

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

// main function of queue using array
int main(){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=-1;
    q->size=maxsize;
    q->array=(int*)malloc((sizeof(int))*q->size);

    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print elements\n");
        printf("Press any other key to quit\n");

        int choice = -1;
        printf("Enter choice : ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Enter the element you want to add : ");
            int element = -1;
            scanf("%d", &element);
            enqueue(q, element);
        }else if(choice==2){
            int dequeued=dequeue(q);
        }else if(choice==3){
            printQueue(q);
        }else{
            return 0;
        }
    }
    return 0;
}

// enqueue
void enqueue(Queue* q, int element){
    if(isFull(q)) {printf("Queue is full!\n");}
    else {q->array[++(q->rear)]=element; printf("%d has been added.\n", element);}
}

// dequeue
int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    else{
        int value=q->array[++(q->front)];
        printf("%d has been removed.\n", value);
        return value;
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