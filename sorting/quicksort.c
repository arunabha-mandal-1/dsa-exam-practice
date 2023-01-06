// Merge sort
#include <stdio.h>
#include <stdlib.h>

// partition
int partition(int* A, int low, int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    while(i<j){
        while(A[i]<pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            int temp1=A[i];
            A[i]=A[j];
            A[j]=temp1;
        }
    }
    int temp2=A[low];
    A[low]=A[j];
    A[j]=temp2;
    return j;
}

// quick sort
void quickSort(int* A, int low, int high){
    int partitionIndex;
    if(low<high){
        partitionIndex=partition(A,low,high);
        quickSort(A, low, partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }
}

// Printing all the elements of an array
void printArray(int* A, int size){
    printf("Elements are : ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// main function
int main(){
    int a[]={5,3,2,4,2,1};
    printArray(a,6);
    quickSort(a,0,5);
    printArray(a,6);

    return 0;
}