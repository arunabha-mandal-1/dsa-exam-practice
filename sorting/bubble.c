// Bubble sort
#include <stdio.h>

// Printing all the elements of an array
void printArray(int* A, int size){
    printf("Elements are : ");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Bubble sort function
// void bubbleSort(int* A, int size){
//     printf("Sorting..............\n");
//     for(int i=0; i<size-1; i++){ // for number of pass
//         printf("Working on pass no %d\n", i+1);
//         for(int j=0; j<size-i-1; j++){ // for comparison in each pass
//             if(A[j]>A[j+1]){
//                 int temp=A[j];
//                 A[j]=A[j+1];
//                 A[j+1]=temp;
//             }
//         }
//     }
// }

// Adaptive Bubble sort function
void bubbleSort(int* A, int size){
    printf("Sorting..............\n");
    int isSorted=0; // to make it adaptive
    for(int i=0; i<size-1; i++){ // for number of pass
        // printf("Working on pass no %d\n", i+1);
        isSorted=1; // assume it is sorted
        for(int j=0; j<size-i-1; j++){ // for comparison in each pass
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                isSorted=0; // if swapping happens, array is not sorted
            }
        }
        if(isSorted==1){
            return;
        }
    }
}

// main function of bubble sort
int main(){
    int A1[]={12, 54, 652, 72, 655, 9};
    int n1=sizeof(A1)/sizeof(A1[0]);

    printf("Before sorting > ");
    printArray(A1, n1);

    bubbleSort(A1, n1);

    printf("After sorting > ");
    printArray(A1, n1);
    return 0;
}