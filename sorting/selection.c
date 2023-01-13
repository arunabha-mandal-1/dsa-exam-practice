// Selection sort
#include <stdio.h>

// Printing all the elements of an array
void printArray(int* A, int size){
    printf("Elements are : ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Selection sort
void selectionSort(int* A, int size){
    for(int i=0; i<=size-2; i++){ // Number of passes
        int minIndex=i;
        for(int j=i+1; j<=size-1; j++){ // Number of comparisons
            if(A[j]<A[minIndex]){
                minIndex=j;
            }
        }
        if(minIndex!=i){ // If the current element is not the minimum, then swap
            int temp=A[i];
            A[i]=A[minIndex];
            A[minIndex]=temp;
        }
    }
}

// main function of selection sort
int main(){
    int A1[]={45, 1, 20, -96, 63, 1};
    int n1=sizeof(A1)/sizeof(A1[0]);

    printf("Before sorting > ");
    printArray(A1,n1);

    selectionSort(A1,n1);

    printf("After sorting > ");
    printArray(A1,n1);
    return 0;
}