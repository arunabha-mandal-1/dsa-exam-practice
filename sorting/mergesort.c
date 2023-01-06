// Merge sort
#include <stdio.h>
#include <stdlib.h>


void merge(int* A, int low, int high, int mid){
    int i=low;
    int j=mid+1;
    int k=0;
    int* B=(int*)calloc(high-low+1, sizeof(int));
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k]=A[j];
        j++;
        k++;
    }
    for(int l=low, m=0; l<=high, m<k; l++, m++){
        A[l]=B[m];
    }
}
void mergeSort(int* A, int low, int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(A,low, mid);
        mergeSort(A,mid+1, high);
        merge(A, low, high, mid);
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
    mergeSort(a,0,5);
    printArray(a,6);

    return 0;
}