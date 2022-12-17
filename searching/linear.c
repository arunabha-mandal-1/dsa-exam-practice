// Linear Search , Time complexity O(n)
#include <stdio.h>

// linear search
void linear_search(int* arr, int size, int key);

// main function
int main(){
    int arr[5]={45, 34, 2, 1, 678};
    linear_search(arr, 5, 68);
    return 0;
}

// linear search
void linear_search(int* arr, int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            printf("%d is present in the array at index %d.", key, i);
            return;
        }
    }
    printf("%d is not present in the array.\n", key);
}