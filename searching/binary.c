// Binary search, Time complexity O(log(n))
#include <stdio.h>

// binary search
void binary_search(int* arr, int size, int key);

// main function
int main(){
    int arr[5]={45, 78, 89, 213, 4521}; // array must be sorted
    binary_search(arr, 5, 4521);
    return 0;
}

// binary search
void binary_search(int* arr, int size, int key){
    int low=0;
    int high=size-1;
    int mid;

    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==key){
            printf("%d is present in the array at index %d.\n", key, mid);
            return;
        }else if(key<arr[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    printf("%d is not present in the array.\n", key);
}