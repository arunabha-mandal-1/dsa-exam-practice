#include <stdio.h>

// Insertion sort
void insertionSort(int* A, int size){
    for(int i=1; i<=size-1; i++){ // total (n-1) passes
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j]>key){ // 'A[j]<key' to sort in descending order
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
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

// main function of insertion sort
int main(){
    int A1[]={12, 54, 65, 7, 7, 9};
    int n1=sizeof(A1)/sizeof(A1[0]);

    printf("Before sorting > ");
    printArray(A1,n1);

    insertionSort(A1,n1);

    printf("After sorting > ");
    printArray(A1,n1);
    return 0;
}

/*
    DRY RUN

    -1  0   1   2   3   4   5
        12  54  65  7   23  9

        12| 54  65  7   23  9   i=1 j=0 key=54
        12  54| 65  7   23  9 => After 1st pass

        12  54| 65  7   23  9   i=2 j=1 key=65
        12  54  65| 7   23  9 => After 2nd pass

        12  54  65| 7   23  9   i=3 j=2 key=7
        7   12  54  65| 23  9   => After 3rd pass

        7   12  54  65| 23  9   i=4 j=3 key=23
        7   12  23  54  65| 9   => After 4th pass

        7   12  23  54  65| 9   i=5 j=4 key=9
        7   9   12  23  54  65  => After 5th pass
*/